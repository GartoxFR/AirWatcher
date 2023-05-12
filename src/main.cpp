#include "auth/AuthentificationLayer.h"
#include "data/Dataset.h"
#include "processing/ProcessingLayer.h"
#include "ui/UI.h"
#include <iostream>
#include <vector>

#include "utils/Iterator.h"

using namespace std;

void test();

int main() {

    vector<int> vec{1, 2, 3, 4, 5, 6, 7};

    for (const auto& i :
         FilteredConstIterator(vec.begin(), vec.end(), [](const auto& item) {
             return item % 2 == 0;
         })) {
        cout << i << endl;
    }

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
    ProcessingLayer proc(&ds);
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
