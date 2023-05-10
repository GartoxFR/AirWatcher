#pragma once

#include <map>
#include <vector>

#include "Cleaner.h"
#include "Measurement.h"
#include "Provider.h"
#include "Sensor.h"
#include "User.h"

typedef std::vector<Measurement> MeasurementVector;

typedef std::vector<Sensor> SensorVector;

typedef std::vector<Cleaner> CleanerVector;

typedef std::map<std::string, Sensor> SensorMap;

typedef std::map<std::string, Provider> ProviderMap;

typedef std::map<std::string, Cleaner> CleanerMap;

typedef std::map<std::string, User> UserMap;

class Dataset {
  public:
    Dataset();

    Sensor* GetSensorById(std::string sensorId) const;
    Provider* GetProviderById(std::string providerId) const;
    Cleaner* GetCleanerById(std::string cleanerId) const;
    User* GetUserById(std::string userId) const;
    const SensorMap& GetSensors() const;
    SensorPointerVector GetSensorsInZone(double latitude, double longitude,
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
