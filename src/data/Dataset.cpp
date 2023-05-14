#include "Dataset.h"
#include "../utils/Utils.h"
#include "Measurement.h"
#include "MeasurementValues.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>
#include <unordered_map>

using namespace std;

FilteredSensorIterator Dataset::GetSensorsInZone(double latitude,
                                                 double longitude,
                                                 double radius) const {
    return FilteredSensorIterator(
        m_sensors.begin(), m_sensors.end(), [=](const auto& entry) {
            return CalculDistance(latitude, longitude,
                                  entry.second.GetLatitude(),
                                  entry.second.GetLongitude()) <= radius;
        });
}

SensorIterator Dataset::GetSensors() const {
    return SensorIterator(m_sensors.begin(), m_sensors.end());
}

static Sensor parseSensor(const string& line) {

    // Static pour ne pas réallouer le buffer pour chaque appel
    // Le constructeur copiera le string donc aucun problème
    // Cela économise plusieurs appels à malloc et free pour chaque appel
    // Car le buffer garde son allocation entre les appels et aura rarement
    // besoin d'être agrandi
    static string id;

    double longitude;
    double latitude;

    istringstream ss(line);

    getline(ss, id, ';');

    ss >> latitude;
    ss.get();
    ss >> longitude;
    ss.get();

    if (!ss) {
        throw "Unable to parse sensor";
    }

    return Sensor(id, latitude, longitude);
}

enum Attribute { O3, NO2, SO2, PM10 };

struct SingleMeasurementValue {
    time_t timestamp;
    double value;
    Attribute attribute;
    string sensorId;
};

static SingleMeasurementValue parseMeasurement(const string& line) {

    // Static pour ne pas réallouer le buffer pour chaque appel
    // Le constructeur copiera le string donc aucun problème
    // Cela économise plusieurs appels à malloc et free pour chaque appel
    // Car le buffer garde son allocation entre les appels et aura rarement
    // besoin d'être agrandi
    static string sensorId;
    static string attribute;
    static string dateStr;

    SingleMeasurementValue value;

    istringstream ss(line);

    getline(ss, dateStr, ';');
    struct tm tm;
    strptime(dateStr.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
    value.timestamp = mktime(&tm);

    getline(ss, sensorId, ';');
    value.sensorId = sensorId;

    getline(ss, attribute, ';');

    ss >> value.value;
    ss.get();

    if (!ss) {
        throw "Unable to parse measurement";
    }

    if (attribute == "O3") {
        value.attribute = O3;
    } else if (attribute == "SO2") {
        value.attribute = SO2;
    } else if (attribute == "NO2") {
        value.attribute = NO2;
    } else if (attribute == "PM10") {
        value.attribute = PM10;
    } else {
        throw "Unkown attribute : " + attribute;
    }

    return value;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

Dataset Dataset::ImportFromCSV(std::string directory) {
    Dataset ds;
    filesystem::path currentFilePath(directory);
    string line;

    {
        // Read sensors and close the file at the end of the scope
        currentFilePath /= "sensors.csv";
        ifstream sensors(currentFilePath);
        while (getline(sensors, line)) {
            Sensor sensor = parseSensor(line);
            ds.m_sensors.insert({sensor.GetSensorId(), std::move(sensor)});
        }
    }

    {
        // Read measurements and close the file at the end of the scope
        currentFilePath.replace_filename("measurements.csv");
        ifstream input(currentFilePath);
        unordered_map<pair<string, time_t>, MeasurementValues, pair_hash>
            valuesMap;

        while (getline(input, line)) {
            SingleMeasurementValue val = parseMeasurement(line);
            auto [it, b] = valuesMap.try_emplace({val.sensorId, val.timestamp},
                                                 -1, -1, -1, -1);
            MeasurementValues& values = (*it).second;
            switch (val.attribute) {
            case O3:
                values.SetO3(val.value);
                break;
            case NO2:
                values.SetNO2(val.value);
                break;
            case SO2:
                values.SetSO2(val.value);
                break;
            case PM10:
                values.SetPM10(val.value);
                break;
            }
        }

        // Safety : m_measurements should never be resized after this point
        ds.m_measurements.reserve(valuesMap.size());
        for (auto& [key, values] : valuesMap) {
            ds.m_measurements.push_back(Measurement(key.second, values));
            ds.GetSensorById(key.first).AssignMeasurement(
                &ds.m_measurements.back());
        }
    }

    return ds;
}
