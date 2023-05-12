#pragma once

#include <map>
#include <vector>

#include "../utils/Iterator.h"
#include "Cleaner.h"
#include "Measurement.h"
#include "Provider.h"
#include "Sensor.h"
#include "User.h"

typedef std::vector<Measurement> MeasurementVector;

typedef std::vector<Sensor> SensorVector;

typedef std::vector<Cleaner> CleanerVector;

typedef std::map<std::string, Sensor> SensorMap;
typedef FilteredConstIterator<SensorMap::const_iterator> FilteredSensorIterator;

typedef std::map<std::string, Provider> ProviderMap;

typedef std::map<std::string, Cleaner> CleanerMap;

typedef std::map<std::string, User> UserMap;

class Dataset {
  public:
    Dataset() = default;

    const Sensor& GetSensorById(const std::string& sensorId) const {
        return m_sensors.at(sensorId);
    }
    Sensor& GetSensorById(const std::string& sensorId) {
        return m_sensors.at(sensorId);
    }
    const Provider& GetProviderById(const std::string& providerId) const {
        return m_providers.at(providerId);
    }
    const Cleaner& GetCleanerById(const std::string& cleanerId) const {
        return m_cleaners.at(cleanerId);
    }
    const User& GetUserById(const std::string& userId) const {
        return m_users.at(userId);
    }
    const SensorMap& GetSensors() const;
    FilteredSensorIterator GetSensorsInZone(double latitude, double longitude,
                                            double radius) const;
    CleanerPointerVector GetCleanersInZone(double latitude, double longitude,
                                           double radius) const;
    static Dataset ImportFromCSV(std::string directory);

  private:
    MeasurementVector m_measurements;
    SensorMap m_sensors;
    ProviderMap m_providers;
    CleanerMap m_cleaners;
    UserMap m_users;
};
