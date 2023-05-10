#pragma once

#include <string>
#include <time.h>
#include "./data/Sensor.h"
#include "./data/Dataset.h"

class ProcessingLayer {
    public:

    ProcessingLayer();

    int CalculQualiteAirZone(double latitude, double longitude, double radius, time_t start, time_t end);

    vector<Sensor*> CalculSimilarite(std::string SensorID, time_t start, time_t end);

    double CalculImpactNettoyeur(std::string CleanerID);

    multimap<double, Value*> CalculFiabilite(std::string SensorID, double rayon);

    double CalculFiabiliteCapteur(std::string SensorID, double rayon);

    double CalculDistance(double latitude1, double latitude2, double longitude1, double longitude2);

    private:

};
