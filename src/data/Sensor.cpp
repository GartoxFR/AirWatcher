#include "Sensor.h"
#include "Measurement.h"

MeasurementTimeRangeIterator Sensor::GetMeasurementsInPeriod(time_t start,
                                                             time_t end) const {
    auto startM = Measurement(start);
    auto endM = Measurement(end);
    auto begin = m_measurements.lower_bound(&startM);
    auto endIt = m_measurements.upper_bound(&endM);

    return MeasurementTimeRangeIterator(begin, endIt);
}
