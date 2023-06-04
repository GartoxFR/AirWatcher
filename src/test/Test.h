#pragma once

#include "../auth/Argument.h"
#include "../auth/AuthentificationLayer.h"
#include "../auth/MenuItem.h"
#include "../data/Dataset.h"
#include "../data/MeasurementValues.h"
#include "../processing/ProcessingLayer.h"
#include "../ui/Printable.h"
#include "../ui/UI.h"
#include "../utils/Iterator.h"
#include "../utils/Utils.h"

class Test {
  public:

    // TEST QUALITE AIR ZONE
    void testCalculQualiteAirZone();
    bool testZonePonctuelle();
    bool testAucunCapteur();
    bool testAucuneMesure();
    bool testPlusieursCapteurs();
    bool testPlusieursMesures();
    bool testPlusieursMesuresPlusieursCapteurs();

    // TEST CALCUL SIMILARITE
    void testCalculSimilarite();
    bool testCapteurSeul();
    bool testCapteurInconnu();
    bool testAucuneMesureSimilarite();
    bool testPlusieursCapteursSimilarite();
    bool testPlusieursMesuresPlusieursCapteursSimilarite();

  private:
    time_t fromStringToDate(std::string);
    bool checkWithError(double a, double ref, double error);
    std::map<std::string, double> invertMultimap(std::multimap<double, const Sensor*>);
};
