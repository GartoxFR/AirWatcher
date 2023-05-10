#include <iostream>
#include "ui/UI.h"

using namespace std;

void test();

int main() {
    cout << "Hello world !" << endl;
    test();
    return 0;
}

void test() {
    UI userInterface;
    string stringInput = userInterface.AskString("Veuillez entrer un string :");
    int intInput = userInterface.AskInt("Veuillez entrer un entier :");
    double doubleInput = userInterface.AskDouble("Veuillez entrer un double :");
    time_t dateInput = userInterface.AskDate("Veuillez entrer une date (yyyy-mm-dd_hh:mm:ss) :");

    cout << "-----------------" << endl;
    cout << stringInput << endl;
    cout << intInput << endl;
    cout << doubleInput << endl;
    cout << ctime(&dateInput) << endl;
}