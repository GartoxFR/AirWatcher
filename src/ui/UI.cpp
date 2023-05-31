#include <iostream>
#include <memory>
#include <memory_resource>
#include <string>
#include <time.h>

using namespace std;

#include "UI.h"

UI::UI(AuthentificationLayer* auth) : m_auth(auth) {}

void UI::StartUI() {
    const Menu& menu = m_auth->GetMenu(UserType::ADMIN);

    bool running = true;
    while (running) {
        int index = 1;

        for (const auto& item : menu) {
            cout << index++ << ". " << item->GetDesc() << endl;
        }

        int choice = AskInt("Menu : ") - 1;
        if (choice >= 0 && (unsigned int) choice < menu.size()) {
            cout << CallMenu(menu[choice]) << endl << endl;
        } else {
            running = false;
        }
    }
}

std::string UI::CallMenu(const MenuItem* menuItem) {
    vector<any> args;
    args.reserve(menuItem->GetArgs().size());

    for (const auto& arg : menuItem->GetArgs()) {
        any a;
        switch (arg.GetType()) {
        case INT:
            a = make_any<int>(AskInt(arg.GetPrompt()));
            args.push_back(a);
            break;
        case DOUBLE:
            a = make_any<double>(AskDouble(arg.GetPrompt()));
            args.push_back(a);
            break;
        case STRING:
            a = make_any<string>(AskString(arg.GetPrompt()));
            args.push_back(a);
            break;
        case DATE:
            a = make_any<time_t>(AskDate(arg.GetPrompt()));
            args.push_back(a);
            break;

        default:
            cerr << "Arg type not implemented" << endl;
        }
    }

    return menuItem->Call(args);
}

const string UI::AskString(const string& prompt) {
    string entree;
    cout << prompt << endl;
    cin >> entree;
    return entree;
}

const int UI::AskInt(const std::string& prompt) {
    int entree;
    cout << prompt << endl;
    cin >> entree;
    while (cin.fail()) {
        cout << prompt << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> entree;
    }
    return entree;
}

const double UI::AskDouble(const std::string& prompt) {
    double entree;
    cout << prompt << endl;
    cin >> entree;
    while (cin.fail()) {
        cout << prompt << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> entree;
    }
    return entree;
}

const time_t UI::AskDate(const std::string& prompt) {
    cout << prompt << endl;
    string entree;
    cin >> entree;
    struct tm tm = {0};
    while (strptime(entree.c_str(), "%Y-%m-%d", &tm) == nullptr) {
        cout << prompt << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> entree;
    }
    return mktime(&tm);
}
