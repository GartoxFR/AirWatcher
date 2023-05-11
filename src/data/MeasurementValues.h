#pragma once

#include <iostream>

class MeasurementValues {
  public:
    MeasurementValues() = default;
    MeasurementValues(double o3, double so2, double no2, double pm10)
        : m_o3(o3), m_so2(so2), m_no2(no2), m_pm10(pm10) {}

    double GetO3() const { return m_o3; }
    double GetSO2() const { return m_so2; }
    double GetNO2() const { return m_no2; }
    double GetPM10() const { return m_pm10; }

    void SetO3(double o3) { m_o3 = o3; }
    void SetSO2(double so2) { m_so2 = so2; }
    void SetNO2(double no2) { m_no2 = no2; }
    void SetPM10(double pm10) { m_pm10 = pm10; }

    int ComputeQualityIndex() const;
    double ComputeSimilarity(const MeasurementValues& values) const;
    MeasurementValues operator+(const MeasurementValues& values) const;
    void operator+=(const MeasurementValues& values);
    MeasurementValues operator-(const MeasurementValues& values) const;
    void operator-=(const MeasurementValues& values);
    MeasurementValues operator/(double value) const;
    void operator/=(double value);
    MeasurementValues operator*(double value) const;
    void operator*=(double value);

    friend std::ostream& operator<<(std::ostream& out,
                                    const MeasurementValues& values);

  private:
    double m_o3;
    double m_so2;
    double m_no2;
    double m_pm10;
};
