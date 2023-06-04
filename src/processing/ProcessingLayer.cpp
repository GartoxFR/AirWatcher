#include "../utils/Utils.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
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
    FilteredSensorIterator allSensors =
        m_dataset->GetSensorsInZone(latitude, longitude, radius);

    for (const auto& [id, sensor] : allSensors) {
        auto mesures = sensor.GetMeasurementsInPeriod(start, end);
        for (auto m : mesures) {
            mesureMoyenne += m->GetValues();
            compteur++;
        }
    }
    if (compteur == 0) {
        return 0;
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

SimilarityMap ProcessingLayer::CalculSimilarite(const std::string& sensorID,
                                                time_t start, time_t end) {
    SimilarityMap map;
    MeasurementValues reference;
    try {
        const Sensor& refSensor = m_dataset->GetSensorById(sensorID);
        size_t count = 0;
        for (const auto& mesure :
             refSensor.GetMeasurementsInPeriod(start, end)) {
            reference += mesure->GetValues();
            count++;
        }
        if (count == 0) {
            return map;
        }

        reference /= count;
        // cout << refSensor.GetSensorId() << " " << reference.GetO3() << endl;

        for (const auto& sensor : m_dataset->GetSensors()) {
            MeasurementValues current;
            // current = MeasurementValues();
            count = 0;
            for (const auto& mesure :
                 sensor.second.GetMeasurementsInPeriod(start, end)) {

                current += mesure->GetValues();
                count++;
            }

            if (count == 0) {
                continue;
            }

            current /= count;
            double similarity = current.ComputeSimilarity(reference);
            map.insert({similarity, &sensor.second});
        }
    } catch (out_of_range ex) {
    }

    return map;
}
