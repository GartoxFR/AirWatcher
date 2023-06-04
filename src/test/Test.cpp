#include <functional>
#include <iostream>
using namespace std;

#include "Test.h"

static void renderTest(const string& testName, std::function<bool()> test) {
    const std::string red("\033[0;31m");
    const std::string green("\033[0;92m");
    const std::string reset("\033[0m");

    cout << "> " << testName << "...";
    bool res = test();
    if (res) {
        cout << green << " [PASS]" << reset << endl << endl;
    } else {
        cout << red << " [FAILED]" << reset << endl << endl;
    }
}

void Test::testCalculQualiteAirZone() {
    cout << "***** Test Calcul Qualite Air Zone *****" << endl << endl;
    renderTest("Test zone capteur seul",
               [this]() { return testZonePonctuelle(); });
    renderTest("Test aucun capteur",
               [this]() { return testAucunCapteur(); });
    renderTest("Test aucune mesure",
               [this]() { return testAucuneMesure(); });
    renderTest("Test plusieurs capteurs",
               [this]() { return testPlusieursCapteurs(); });
    renderTest("Test plusieurs mesures",
               [this]() { return testPlusieursMesures(); });
    renderTest("Test plusieurs mesures, plusieurs capteurs",
               [this]() { return testPlusieursMesuresPlusieursCapteurs(); });
}

bool Test::testZonePonctuelle() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-1");
    ProcessingLayer pl(&ds);
    int index =
        pl.CalculQualiteAirZone(44, -1, 10, fromStringToDate("2019-01-01"),
                                fromStringToDate("2019-01-02"));

    return (index == 7);
}

bool Test::testAucunCapteur() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-2");
    ProcessingLayer pl(&ds);
    int index =
        pl.CalculQualiteAirZone(45, 1, 1, fromStringToDate("2019-01-01"),
                                fromStringToDate("2019-01-02"));

    return (index == 0);
}

bool Test::testAucuneMesure() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-3");
    ProcessingLayer pl(&ds);
    int index =
        pl.CalculQualiteAirZone(44, -1, 1, fromStringToDate("2019-01-02"),
                                fromStringToDate("2019-01-03"));
    return (index == 0);
}

bool Test::testPlusieursCapteurs() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-4");
    ProcessingLayer pl(&ds);
    int index =
        pl.CalculQualiteAirZone(44, -1, 100, fromStringToDate("2019-01-01"),
                                fromStringToDate("2019-01-02"));
    return (index == 7);
}

bool Test::testPlusieursMesures() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-5");
    ProcessingLayer pl(&ds);
    int index =
        pl.CalculQualiteAirZone(44, -1, 0, fromStringToDate("2019-01-01"),
                                fromStringToDate("2019-01-03"));
    return (index == 7);
}

bool Test::testPlusieursMesuresPlusieursCapteurs() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test1-6");
    ProcessingLayer pl(&ds);
    int index =
        pl.CalculQualiteAirZone(44, -1, 100, fromStringToDate("2019-01-01"),
                                fromStringToDate("2019-01-03"));
    return (index == 8);
}

///////////////////////////////////////////////////////////////////////////

void Test::testCalculSimilarite() {
    cout << "***** Test Calcul Similarite *****" << endl << endl;
    renderTest("Test capteur seul",
               [this]() { return testCapteurSeul(); });
    renderTest("Test capteur inconnu",
               [this]() { return testCapteurInconnu(); });
    renderTest("Test aucune mesure",
               [this]() { return testAucuneMesureSimilarite(); });
    renderTest("Test plusieurs capteurs",
               [this]() { return testPlusieursCapteursSimilarite(); });
    renderTest("test plusieurs mesures, plusieurs capteurs",
               [this]() { return testPlusieursMesuresPlusieursCapteursSimilarite(); });
    renderTest("Test capteur inconnu",
               [this]() { return testCapteurInconnu(); });
}

bool Test::testCapteurSeul() {
    int expectedLength = 1;
    pair<double, string> expected[] = {make_pair(0, "Sensor0")};

    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-1");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m =
        pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-01"),
                            fromStringToDate("2019-01-02"));
    if (m.size() != expectedLength) {
        return false;
    }

    int i = 0;
    double error = 0.1;
    for (const auto& entry : m) {
        if (!(checkWithError(entry.first, expected[i].first, error) &&
              expected[i].second == entry.second->GetSensorId())) {
            return false;
        }

        ++i;
    }
    return true;
}

bool Test::testCapteurInconnu() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-2");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m =
        pl.CalculSimilarite("Sensor1", fromStringToDate("2019-01-01"),
                            fromStringToDate("2019-01-02"));
    return (m.empty());
}

bool Test::testAucuneMesureSimilarite() {
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-3");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m =
        pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-02"),
                            fromStringToDate("2019-01-03"));
    return (m.empty());
}

bool Test::testPlusieursCapteursSimilarite() {
    int expectedLength = 3;
    pair<double, string> expected[] = {make_pair(0, "Sensor0"),
                                       make_pair(412.54, "Sensor1"),
                                       make_pair(1000.54, "Sensor2")};
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-4");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m =
        pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-01"),
                            fromStringToDate("2019-01-02"));

    if (m.size() != expectedLength) {
        return false;
    }

    int i = 0;
    double error = 0.1;
    for (const auto& entry : m) {
        if (!(checkWithError(entry.first, expected[i].first, error) &&
              expected[i].second == entry.second->GetSensorId())) {
            return false;
        }

        ++i;
    }
    return true;
}

bool Test::testPlusieursMesuresPlusieursCapteursSimilarite() {
    int expectedLength = 3;
    pair<double, string> expected[] = {make_pair(0, "Sensor0"),
                                       make_pair(406.82, "Sensor1"),
                                       make_pair(951.09, "Sensor2")};
    const Dataset ds = Dataset::ImportFromCSV("src/test/test2-5");
    ProcessingLayer pl(&ds);
    multimap<double, const Sensor*> m =
        pl.CalculSimilarite("Sensor0", fromStringToDate("2019-01-01"),
                            fromStringToDate("2019-01-03"));
    map<string, double> new_m = invertMultimap(m);

    if (m.size() != expectedLength) {
        return false;
    }

    int i = 0;
    double error = 0.1;
    for (const auto& entry : m) {
        if (!(checkWithError(entry.first, expected[i].first, error) &&
              expected[i].second == entry.second->GetSensorId())) {
            return false;
        }

        ++i;
    }
    return true;
}

time_t Test::fromStringToDate(string myString) {
    struct tm tm = {0};
    strptime(myString.c_str(), "%Y-%m-%d", &tm);
    return mktime(&tm);
}

bool Test::checkWithError(double a, double ref, double error) {
    return (a >= (ref - error) && a <= (ref + error));
}

map<string, double> Test::invertMultimap(multimap<double, const Sensor*> m) {
    map<string, double> new_m;
    for (const auto& it : m) {
        new_m.insert(make_pair(it.second->GetSensorId(), it.first));
    }
    return new_m;
}
