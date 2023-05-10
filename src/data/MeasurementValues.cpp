#include "MeasurementValues.h"

int MeasurementValues::ComputeQualityIndex() const {
    return 0;
}

int MeasurementValues::ComputeSimilarity(const MeasurementValues& values) const {
    return 0;
}

MeasurementValues MeasurementValues::operator+(const MeasurementValues& values) const {
    MeasurementValues newValues = MeasurementValues(this->GetO3()+values.GetO3(),this->GetSO2()+values.GetSO2(),this->GetNO2()+values.GetNO2(),this->GetPM10()+values.GetPM10());
    return newValues;
}

void MeasurementValues::operator+=(const MeasurementValues& values) {
    this->m_o3 += values.GetO3();
    this->m_so2 += values.GetSO2();
    this->m_no2 += values.GetNO2();
    this->m_pm10 += values.GetPM10();
}

MeasurementValues MeasurementValues::operator-(const MeasurementValues& values) const {
    MeasurementValues newValues = MeasurementValues(this->GetO3()-values.GetO3(),this->GetSO2()-values.GetSO2(),this->GetNO2()-values.GetNO2(),this->GetPM10()-values.GetPM10());
    return newValues;
}

void MeasurementValues::operator-=(const MeasurementValues& values) {
    this->m_o3 -= values.GetO3();
    this->m_so2 -= values.GetSO2();
    this->m_no2 -= values.GetNO2();
    this->m_pm10 -= values.GetPM10();
}

MeasurementValues MeasurementValues::operator/(double value) const {
    MeasurementValues newValues = MeasurementValues(this->GetO3()/value,this->GetSO2()/value,this->GetNO2()/value,this->GetPM10()/value);
    return newValues;
}

void MeasurementValues::operator/=(double value) {
    this->m_o3 /= value;
    this->m_so2 /= value;
    this->m_no2 /= value;
    this->m_pm10 /= value;
}

MeasurementValues MeasurementValues::operator*(double value) const {
    MeasurementValues newValues = MeasurementValues(this->GetO3()*value,this->GetSO2()*value,this->GetNO2()*value,this->GetPM10()*value);
    return newValues;
}

void MeasurementValues::operator*=(double value) {
    this->m_o3 *= value;
    this->m_so2 *= value;
    this->m_no2 *= value;
    this->m_pm10 *= value;
}

