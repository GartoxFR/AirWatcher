#include "auth/AuthentificationLayer.h"
#include "processing/ProcessingLayer.h"
#include "ui/UI.h"
#include <iostream>

using namespace std;

void test();

int main() {

    ProcessingLayer proc;
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
