#include <iostream>
using namespace std;

#include "Test.h"

void Test::testCalculQualiteAirZone() {
    cout << "Test zone ponctuelle = " << testZonePonctuelle() << endl;
    cout << "Test aucun capteur = " << testAucunCapteur() << endl;
    cout << "Test aucune mesure = " << testAucuneMesure() << endl;
    cout << "Test plusieurs capteurs = " << testPlusieursCapteurs() << endl;
    cout << "Test plusieurs mesures = " << testPlusieursMesures() << endl;
    cout << "Test plusieurs mesures, plusieurs capteurs = " << testPlusieursMesuresPlusieursCapteurs() << endl;
}

bool Test::testZonePonctuelle() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-1");
    ProcessingLayer pl(&ds);
    return (pl.CalculQualiteAirZone(44, -1, 1, fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-02 12:00:01")) == 0);
}

bool Test::testAucunCapteur() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-2");
    ProcessingLayer pl(&ds);
    return (pl.CalculQualiteAirZone(45, 1, 1, fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01")) == 0);
}

bool Test::testAucuneMesure() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-3");
    ProcessingLayer pl(&ds);
    return (pl.CalculQualiteAirZone(44, -1, 1, fromStringToDate("2019-01-02 12:00:00"), fromStringToDate("2019-01-02 12:00:01")) == 0);
}

bool Test::testPlusieursCapteurs() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-4");
    ProcessingLayer pl(&ds);
    return (pl.CalculQualiteAirZone(44, -1, 100, fromStringToDate("2019-01-02 12:00:00"), fromStringToDate("2019-01-02 12:00:01")) == 7);
}

bool Test::testPlusieursMesures() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-5");
    ProcessingLayer pl(&ds);
    return (pl.CalculQualiteAirZone(44, -1, 0, fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-02 12:00:01")) == 7);
}

bool Test::testPlusieursMesuresPlusieursCapteurs() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-6");
    ProcessingLayer pl(&ds);
    return (pl.CalculQualiteAirZone(44, -1, 100, fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-02 12:00:01")) == 8);
}

///////////////////////////////////////////////////////////////////////////

void Test::testCalculSimilarite() {
    cout << "Test capteur seul = " << testCapteurSeul() << endl;
    cout << "Test capteur inconnu = " << testCapteurInconnu() << endl;
    cout << "Test aucune mesure = " << testAucuneMesureSimilarite() << endl;
    cout << "Test plusieurs capteurs = " << testPlusieursCapteursSimilarite() << endl;
    cout << "Test plusieurs mesures, plusieurs capteurs = " << testPlusieursMesuresPlusieursCapteursSimilarite() << endl;
}

bool Test::testCapteurSeul() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-1");
    ProcessingLayer pl(&ds);
    return (pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01")).empty());
}

bool Test::testCapteurInconnu() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-2");
    ProcessingLayer pl(&ds);
    return (pl.CalculSimilarite("Sensor1", fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01")).empty());
}

bool Test::testAucuneMesureSimilarite() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-3");
    ProcessingLayer pl(&ds);
    return (pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-02 12:00:00"), fromStringToDate("2019-01-02 12:00:01")).empty());
}

bool Test::testPlusieursCapteursSimilarite() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-4");
    ProcessingLayer pl(&ds);
    return (pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-01 12:00:01")).empty());
}

bool Test::testPlusieursMesuresPlusieursCapteursSimilarite() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-5");
    ProcessingLayer pl(&ds);
    return (pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-01 12:00:00"), fromStringToDate("2019-01-02 12:00:01")).empty());
}

time_t Test::fromStringToDate(string myString) {
    struct tm tm = {0};
    strptime(myString.c_str(), "%Y-%m-%d", &tm);
    return mktime(&tm);
}