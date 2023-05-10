#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

#include "ProcessingLayer.h"

int ProcessingLayer::CalculQualiteAirZone(double latitude, double longitude,
                                          double radius, time_t start,
                                          time_t end) {
    vector<Measurement*> singleSensorMeas;
    MeasurementValues mesureMoyenne(0, 0, 0, 0);
    int compteur = 0;
    const auto& allSensors =
        m_dataset->GetSensorsInZone(latitude, longitude, radius);

    for (int i = 0; i < allSensors.size(); i++) {
        singleSensorMeas = allSensors[i]->GetMeasurementsInPeriod(start, end);
        for (int j = 0; j < singleSensorMeas.size(); j++) {
            mesureMoyenne += singleSensorMeas[j]->GetValues();
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

double ProcessingLayer::CalculDistance(double latitude1, double latitude2,
                                       double longitude1, double longitude2) {}
