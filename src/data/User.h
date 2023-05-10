#pragma once

#include <vector>
#include "Sensor.h"

typedef std::vector<Sensor*>
    SensorPointerVector;

class User {
  public:
    User(std::string userId)
        : m_userId(userId) {}

    int GetPoints() const { return m_points; }
    void AddPoints(int points) const;

  private:
    std::string m_userId;
    SensorPointerVector m_sensors;
    int m_points;
};