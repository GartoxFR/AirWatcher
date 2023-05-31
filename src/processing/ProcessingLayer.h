#pragma once

#include "../data/Dataset.h"
#include "../data/Sensor.h"
#include <map>
#include <string>
#include <time.h>
#include <vector>

using SimilarityMap = std::multimap<double, const Sensor*>;

class ProcessingLayer {
  public:
    ProcessingLayer(const Dataset* dataset) : m_dataset(dataset) {}

    int CalculQualiteAirZone(double latitude, double longitude, double radius,
                             time_t start, time_t end);

    SimilarityMap CalculSimilarite(const std::string& sensorID, time_t start,
                                   time_t end);

  private:
    const Dataset* m_dataset;
};
