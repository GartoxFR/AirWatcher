#include "Measurement.h"
#include "time.h"

std::ostream& operator<<(std::ostream& out, const Measurement& values) {
    out << "{date: " << ctime(&values.m_timestamp);
    out << "values: {" << values.GetValues();

    out << "}}";

    return out;
}
