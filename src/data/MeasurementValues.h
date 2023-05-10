#pragma once

class MeasurementValues {
  public:
    MeasurementValues(double o3, double so2, double no2, double pm10)
        : m_o3(o3), m_so2(so2), m_no2(no2), m_pm10(pm10) {}

    double GetO3() const { return m_o3; }
    double GetSO2() const { return m_so2; }
    double GetNO2() const { return m_no2; }
    double GetPM10() const { return m_pm10; }
    int ComputeQualityIndex() const;
    int ComputeSimilarity(const MeasurementValues& values) const;
    MeasurementValues operator+(const MeasurementValues& values) const;
    void operator+=(const MeasurementValues& values);
    MeasurementValues operator-(const MeasurementValues& values) const;
    void operator-=(const MeasurementValues& values);
    MeasurementValues operator/(double value) const;
    void operator/=(double value);
    MeasurementValues operator*(double value) const;
    void operator*=(double value);

  private:
    double m_o3;
    double m_so2;
    double m_no2;
    double m_pm10;
};