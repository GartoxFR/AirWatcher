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
    
}