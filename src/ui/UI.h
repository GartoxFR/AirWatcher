#pragma once 

#include <string>
#include <time.h>


class UI {

    public:

        UI();

        ~UI();

        const std::string AskString (const std::string& prompt);

        const int AskInt (const std::string& prompt);

        const double AskDouble (const std::string& prompt);

        const time_t AskDate (const std::string& prompt);

    private:

};