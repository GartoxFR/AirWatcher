#pragma once

#include "Measurement.h"
#include "User.h"
#include <set>
#include <string>
#include <vector>

typedef std::set<Measurement*> MeasurementPointerSet;

typedef std::vector<Measurement*> MeasurementPointerVector;

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
    MeasurementPointerVector GetMeasurementsInPeriod(time_t start,
                                                     time_t end) const;
    const User* GetUser() const { return m_user; }

  private:
    std::string m_sensorId;
    double m_latitude;
    double m_longitude;
    MeasurementPointerSet m_measurements;
    User* m_user;
};
