#pragma once

#include "Measurement.h"
#include "User.h"
#include <set>
#include <string>
#include <vector>

struct MeasurementDateComp {
    bool operator()(const Measurement* m1, const Measurement* m2) const {
        return m1->GetTimestamp() < m2->GetTimestamp();
    }
};

typedef std::set<const Measurement*, MeasurementDateComp> MeasurementPointerSet;

typedef std::vector<const Measurement*> MeasurementPointerVector;

class MeasurementTimeRangeIterator {
  public:
    MeasurementTimeRangeIterator(
        const MeasurementPointerSet::const_iterator& begin,
        const MeasurementPointerSet::const_iterator& end)
        : m_begin(begin), m_end(end) {}

    MeasurementPointerSet::const_iterator begin() const { return m_begin; }
    MeasurementPointerSet::const_iterator end() const { return m_end; }

  private:
    MeasurementPointerSet::const_iterator m_begin;
    MeasurementPointerSet::const_iterator m_end;
};

class Sensor {
  public:
    Sensor(const std::string& sensorId, double latitude, double longitude)
        : m_sensorId(sensorId), m_latitude(latitude), m_longitude(longitude) {}

    const std::string& GetSensorId() const { return m_sensorId; }
    const double GetLatitude() const { return m_latitude; }
    const double GetLongitude() const { return m_longitude; }
    const MeasurementPointerSet& GetMeasurements() const {
        return m_measurements;
    }
    MeasurementTimeRangeIterator GetMeasurementsInPeriod(time_t start,
                                                         time_t end) const;

    void AssignMeasurement(const Measurement* m) { m_measurements.insert(m); }
    const User* GetUser() const { return m_user; }

  private:
    std::string m_sensorId;
    double m_latitude;
    double m_longitude;
    MeasurementPointerSet m_measurements;
    User* m_user;
};
