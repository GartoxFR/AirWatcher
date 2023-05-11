#include "MeasurementValues.h"
#include <math.h>

int MeasurementValues::ComputeQualityIndex() const {
    static int tabO3[9] = {29, 54, 79, 104, 129, 149, 179, 209, 239};
    static int tabSO2[9] = {39, 79, 119, 159, 199, 249, 299, 399, 499};
    static int tabNO2[9] = {29, 54, 84, 109, 134, 164, 199, 274, 399};
    static int tabPM10[9] = {6, 13, 20, 27, 34, 41, 49, 64, 79};
    int indice = 10;

    for (int i = 9; i > 0; i--) {
        if (this->GetO3() > tabO3[i] || this->GetSO2() > tabSO2[i] ||
            this->GetNO2() > tabNO2[i] || this->GetPM10() > tabPM10[i]) {
            break;
        }
        indice--;
    }

    return indice;
}

double
MeasurementValues::ComputeSimilarity(const MeasurementValues& values) const {
    double value = pow(this->GetO3() - values.GetO3(), 2) +
                   pow(this->GetSO2() - values.GetSO2(), 2) +
                   pow(this->GetNO2() - values.GetNO2(), 2) +
                   pow(this->GetPM10() - values.GetPM10(), 2);
    return value;
}

MeasurementValues
MeasurementValues::operator+(const MeasurementValues& values) const {
    MeasurementValues newValues = MeasurementValues(
        this->GetO3() + values.GetO3(), this->GetSO2() + values.GetSO2(),
        this->GetNO2() + values.GetNO2(), this->GetPM10() + values.GetPM10());
    return newValues;
}

void MeasurementValues::operator+=(const MeasurementValues& values) {
    this->m_o3 += values.GetO3();
    this->m_so2 += values.GetSO2();
    this->m_no2 += values.GetNO2();
    this->m_pm10 += values.GetPM10();
}

MeasurementValues
MeasurementValues::operator-(const MeasurementValues& values) const {
    MeasurementValues newValues = MeasurementValues(
        this->GetO3() - values.GetO3(), this->GetSO2() - values.GetSO2(),
        this->GetNO2() - values.GetNO2(), this->GetPM10() - values.GetPM10());
    return newValues;
}

void MeasurementValues::operator-=(const MeasurementValues& values) {
    this->m_o3 -= values.GetO3();
    this->m_so2 -= values.GetSO2();
    this->m_no2 -= values.GetNO2();
    this->m_pm10 -= values.GetPM10();
}

MeasurementValues MeasurementValues::operator/(double value) const {
    MeasurementValues newValues =
        MeasurementValues(this->GetO3() / value, this->GetSO2() / value,
                          this->GetNO2() / value, this->GetPM10() / value);
    return newValues;
}

void MeasurementValues::operator/=(double value) {
    this->m_o3 /= value;
    this->m_so2 /= value;
    this->m_no2 /= value;
    this->m_pm10 /= value;
}

MeasurementValues MeasurementValues::operator*(double value) const {
    MeasurementValues newValues =
        MeasurementValues(this->GetO3() * value, this->GetSO2() * value,
                          this->GetNO2() * value, this->GetPM10() * value);
    return newValues;
}

void MeasurementValues::operator*=(double value) {
    this->m_o3 *= value;
    this->m_so2 *= value;
    this->m_no2 *= value;
    this->m_pm10 *= value;
}

std::ostream& operator<<(std::ostream& out, const MeasurementValues& values) {
    out << "{ ";
    out << "O3: " << values.GetO3();
    out << "SO2: " << values.GetSO2();
    out << "NO2: " << values.GetNO2();
    out << "PM10: " << values.GetPM10();
    out << " }";
    return out;
}
