#pragma once

#include "MeasurementValues.h"
#include <time.h>

class Measurement {
  public:
    Measurement(const time_t& timestamp,
                MeasurementValues values = MeasurementValues())
        : m_timestamp(timestamp), m_values(values) {}

    time_t GetTimestamp() const { return m_timestamp; }
    const MeasurementValues& GetValues() const { return m_values; }

    friend std::ostream& operator<<(std::ostream& out,
                                    const Measurement& values);

  private:
    time_t m_timestamp;
    MeasurementValues m_values;
};
