#pragma once

#include "../data/Dataset.h"
#include "../data/Sensor.h"
#include <map>
#include <string>
#include <time.h>
#include <vector>

class ProcessingLayer {
  public:
    ProcessingLayer(const Dataset* dataset) : m_dataset(dataset) {}

    int CalculQualiteAirZone(double latitude, double longitude, double radius,
                             time_t start, time_t end);

    std::vector<Sensor*> CalculSimilarite(std::string SensorID, time_t start,
                                          time_t end);

    double CalculImpactNettoyeur(std::string CleanerID);

    std::multimap<double, MeasurementValues*>
    CalculFiabilite(std::string SensorID, double rayon);

    double CalculFiabiliteCapteur(std::string SensorID, double rayon);

  private:
    const Dataset* m_dataset;
};
