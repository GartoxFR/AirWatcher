#pragma once

#include <time.h>
#include "MeasurementValues.h"

class Measurement {
  public:
    Measurement(const time_t& timestamp, MeasurementValues values)
        : m_timestamp(timestamp), m_values(values) {}

    time_t GetTimestamp() const { return m_timestamp; }
    const MeasurementValues& GetValues() const { return m_values; }


  private:
    time_t m_timestamp;
    MeasurementValues m_values;
};
