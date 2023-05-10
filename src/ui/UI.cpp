#include <string>
#include <time.h>
#include <iostream>
using namespace std;

#include "UI.h"


UI::UI()
{

}

UI::~UI()
{

}

const string UI::AskString (const string& prompt)
{
    string entree;
    cout << prompt << endl;
    cin >> entree;
    return entree;
}

const int UI::AskInt (const std::string& prompt)
{
    int entree;
    cout << prompt << endl;
    cin >> entree;
    while(cin.fail()) {
        cout << prompt << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> entree;
    }
    return entree;
}

const double UI::AskDouble (const std::string& prompt)
{
    double entree;
    cout << prompt << endl;
    cin >> entree;
    while(cin.fail()) {
        cout << prompt << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> entree;
    }
    return entree;
}

const time_t UI::AskDate (const std::string& prompt)
{
    cout << prompt << endl;
    string entree;
    cin >> entree;
    struct tm tm = {0};
    while (strptime(entree.c_str(), "%Y-%m-%d_%H:%M:%S", &tm) == nullptr) {
        cout << prompt << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> entree;
    }
    return mktime(&tm);
}