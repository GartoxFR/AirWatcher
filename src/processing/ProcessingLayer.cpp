#include <cmath>
#include <iostream>
#include <math.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

#include "ProcessingLayer.h"

int ProcessingLayer::CalculQualiteAirZone(double latitude, double longitude,
                                          double radius, time_t start,
                                          time_t end) {
    MeasurementValues mesureMoyenne(0, 0, 0, 0);
    int compteur = 0;
    const auto& allSensors =
        m_dataset->GetSensorsInZone(latitude, longitude, radius);

    for (auto sensor : allSensors) {
        auto mesures = sensor->GetMeasurementsInPeriod(start, end);
        for (auto m : mesures) {
            mesureMoyenne += m->GetValues();
            compteur++;
        }
    }
    mesureMoyenne /= compteur;
    return mesureMoyenne.ComputeQualityIndex();
}
// Entrée : double latitude, double longitude, double rayon, time_t dateDebut,
// time_t dateFin Précondition : L'utilisateur a tapé les coordonnées de la zone
// dont il souhaite avoir la qualité de l'air Sortie : int Début : vector <-
// Chercher les sensors dans la zone définie par la latitude, longitude et rayon
// Pour t <- 0 à vector.size()
// vectorMesure <- Chercher les mesures dans la période spéficiée (<dateFin et
// >dateDebut) mesureMoyenne = 0 Pour u <- 0 à vectorMesure.size() mesureMoyenne
// <- mesureMoyenne.operator+=(mesure u) Fin pour Fin pour mesureMoyenne <-
// mesureMoyenne.operator/=(vectorMesure.size()) indice <- Calcul de qualité de
// l'air à partir de mesureMoyenne Retourne indice Fin

vector<Sensor*> ProcessingLayer::CalculSimilarite(std::string SensorID,
                                                  time_t start, time_t end) {}

double ProcessingLayer::CalculImpactNettoyeur(std::string CleanerID) {}

multimap<double, MeasurementValues*>
ProcessingLayer::CalculFiabilite(std::string SensorID, double rayon) {}

double ProcessingLayer::CalculFiabiliteCapteur(std::string SensorID,
                                               double rayon) {}

const double EARTH_RADIUS = 6371.009;
double ProcessingLayer::CalculDistance(double latitude1, double longitude1,
                                       double latitude2,
                                       double longitude2) const {
    // Conversion to rad
    latitude1 = latitude1 * (M_PI / 180);
    latitude2 = latitude2 * (M_PI / 180);
    longitude1 = longitude1 * (M_PI / 180);
    longitude2 = longitude2 * (M_PI / 180);

    double haversine = (pow(sin((1.0 / 2) * (latitude2 - latitude1)), 2)) +
                       ((cos(latitude1)) * (cos(latitude2)) *
                        (pow(sin((1.0 / 2) * (longitude2 - longitude1)), 2)));

    double d = EARTH_RADIUS * 2 * asin(min(1.0, sqrt(haversine)));
    return d;
}
