#include "auth/AuthentificationLayer.h"
#include "data/Dataset.h"
#include "processing/ProcessingLayer.h"
#include "ui/UI.h"
#include <iostream>

using namespace std;

void test();

int main() {

    const Dataset ds = Dataset::ImportFromCSV("dataset");

    // UI userInterface(nullptr);
    // time_t start = userInterface.AskDate("start");
    // time_t end = userInterface.AskDate("end");
    // for (const auto& m :
    //      ds.GetSensorById("Sensor1").GetMeasurementsInPeriod(start, end)) {
    //     cout << *m << endl;
    // }
    // cout << "Mesure au pif "
    //      << (*ds.GetSensorById("Sensor1").GetMeasurements().begin())
    //             ->GetValues()
    //             .GetO3()
    //      << endl;

    // Todo init dataset layer
    ProcessingLayer proc(nullptr);
    cout << proc.CalculDistance(51, 42.7, 52, 43) << endl;
    AuthentificationLayer auth(&proc);
    UI ui(&auth);
    ui.StartUI();

    return 0;
}

void test() {
    UI userInterface(nullptr);
    string stringInput = userInterface.AskString("Veuillez entrer un string:");
    int intInput = userInterface.AskInt("Veuillez entrer un entier :");
    double doubleInput = userInterface.AskDouble("Veuillez entrer un double:");
    time_t dateInput = userInterface.AskDate(
        "Veuillez entrer une date(yyyy-mm-dd_hh:mm:ss) :");

    cout << "-----------------" << endl;
    cout << stringInput << endl;
    cout << intInput << endl;
    cout << doubleInput << endl;
    cout << ctime(&dateInput) << endl;
}
