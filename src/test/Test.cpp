#include <iostream>
using namespace std;

#include "Test.h"

void Test::testCalculQualiteAirZone() {
    cout << "***** Test Calcul Qualite Air Zone *****" << endl;
    cout << "> Test zone ponctuelle" << endl;
    testZonePonctuelle();
    cout << "> Test aucun capteur" << endl;
    testAucunCapteur();
    cout << "> Test aucune mesure" << endl;
    testAucuneMesure();
    cout << "> Test plusieurs capteurs" << endl;
    testPlusieursCapteurs();
    cout << "> Test plusieurs mesures" << endl;
    testPlusieursMesures();
    cout << "> Test plusieurs mesures, plusieurs capteurs" << endl;
    testPlusieursMesuresPlusieursCapteurs();
}

bool Test::testZonePonctuelle() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-1");
    ProcessingLayer pl(&ds);
    cout << "*** Données utilisées" << endl;
    int index = pl.CalculQualiteAirZone(44, -1, 0, fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01"));
    cout << "*** Indice ATMO calculé: " << index << endl;
    cout << "*** Résultat: " << (index == 7) << endl;
    return (index == 7);
}

bool Test::testAucunCapteur() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-2");
    ProcessingLayer pl(&ds);
    cout << "*** Données utilisées" << endl;
    int index = pl.CalculQualiteAirZone(45, 1, 1, fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01"));
    cout << "*** Indice ATMO calculé: " << index << endl;
    cout << "*** Résultat: " << (index == 0) << endl;
    return (index == 0);
}

bool Test::testAucuneMesure() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-3");
    ProcessingLayer pl(&ds);
    cout << "*** Données utilisées" << endl;
    int index = pl.CalculQualiteAirZone(44, -1, 1, fromStringToDate("2019-01-02 12:00:00"), fromStringToDate("2019-01-02 12:00:01"));
    cout << "*** Indice ATMO calculé: " << index << endl;
    cout << "*** Résultat: " << (index == 0) << endl;
    return (index == 0);
}

bool Test::testPlusieursCapteurs() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-4");
    ProcessingLayer pl(&ds);
    cout << "*** Données utilisées" << endl;
    int index = pl.CalculQualiteAirZone(44, -1, 100, fromStringToDate("2019-01-02 12:00:00"), fromStringToDate("2019-01-02 12:00:01"));
    cout << "*** Indice ATMO calculé: " << index << endl;
    cout << "*** Résultat: " << (index == 7) << endl;
    return (index == 7);
}

bool Test::testPlusieursMesures() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-5");
    ProcessingLayer pl(&ds);
    cout << "*** Données utilisées" << endl;
    int index = pl.CalculQualiteAirZone(44, -1, 0, fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-02 12:00:01"));
    cout << "*** Indice ATMO calculé: " << index << endl;
    cout << "*** Résultat: " << (index == 7) << endl;
    return (index == 7);
}

bool Test::testPlusieursMesuresPlusieursCapteurs() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-6");
    ProcessingLayer pl(&ds);
    int index = pl.CalculQualiteAirZone(44, -1, 100, fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-02 12:00:01"));
    cout << "*** Indice ATMO calculé: " << index << endl;
    cout << "*** Résultat: " << (index == 8) << endl;
    return (index == 8);
}

///////////////////////////////////////////////////////////////////////////

void Test::testCalculSimilarite() {
    cout << "***** Test Calcul Similarite *****" << endl;
    cout << "Test capteur seul = " << testCapteurSeul() << endl;
    cout << "Test capteur inconnu = " << testCapteurInconnu() << endl;
    cout << "Test aucune mesure = " << testAucuneMesureSimilarite() << endl;
    cout << "Test plusieurs capteurs = " << testPlusieursCapteursSimilarite() << endl;
    cout << "Test plusieurs mesures, plusieurs capteurs = " << testPlusieursMesuresPlusieursCapteursSimilarite() << endl;
}

bool Test::testCapteurSeul() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-1");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m = pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01"));
    return (m.empty());
}

bool Test::testCapteurInconnu() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-2");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m = pl.CalculSimilarite("Sensor1", fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01"));
    return (m.empty());
}

bool Test::testAucuneMesureSimilarite() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-3");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m = pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-02 12:00:00"), fromStringToDate("2019-01-02 12:00:01"));
    return (m.empty());
}

bool Test::testPlusieursCapteursSimilarite() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-4");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m = pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01"));
    multimap<string, double> new_m = invertMultimap(m);
    double value_sensor1 = new_m.find("Sensor1")->second;
    double value_sensor2 = new_m.find("Sensor2")->second;
    double error = 0.1;
    return (checkWithError(value_sensor1, 412.54, error) && checkWithError(value_sensor2, 1000.54, error));
}

bool Test::testPlusieursMesuresPlusieursCapteursSimilarite() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-5");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m = pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01"));
    multimap<string, double> new_m = invertMultimap(m);
    double value_sensor1 = new_m.find("Sensor1")->second;
    double value_sensor2 = new_m.find("Sensor2")->second;
    double error = 0.1;
    return (checkWithError(value_sensor1, 406.82, error) && checkWithError(value_sensor2, 951.09, error));
}

time_t Test::fromStringToDate(string myString) {
    struct tm tm = {0};
    strptime(myString.c_str(), "%Y-%m-%d", &tm);
    return mktime(&tm);
}

bool Test::checkWithError(double a, double ref, double error) {
    return (a >= (ref - error) && a <= (ref + error));
}

multimap<string, double> Test::invertMultimap(multimap<double, const Sensor*> m) {
    multimap<string, double> new_m;
    for (const auto& it : m) {
        new_m.insert(make_pair(it.second->GetSensorId(), it.first));
    }
    return new_m;
}