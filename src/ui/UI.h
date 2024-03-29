#pragma once

#include "../auth/AuthentificationLayer.h"
#include <string>
#include <time.h>

class UI {

  public:
    UI(AuthentificationLayer* auth);

    void StartUI();

    std::string CallMenu(const MenuItem* menuItem);

    const std::string AskString(const std::string& prompt);

    const int AskInt(const std::string& prompt);

    const double AskDouble(const std::string& prompt);

    const time_t AskDate(const std::string& prompt);

  private:
    AuthentificationLayer* m_auth;
};
