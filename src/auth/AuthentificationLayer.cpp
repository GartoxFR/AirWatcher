#include "AuthentificationLayer.h"

#include <any>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

AuthentificationLayer::AuthentificationLayer(ProcessingLayer* processingLayer)
    : m_processingLayer(processingLayer) {

    // todo

    const auto& moyenneZoneMenuItem = AddMenuItem(
        "Calculer la qualité de l'air dans une zone",
        [this](const auto& args) {
            double latitude = any_cast<double>(args[0]);
            double longitude = any_cast<double>(args[1]);
            double radius = any_cast<double>(args[2]);

            time_t start = any_cast<time_t>(args[3]);
            time_t end = any_cast<time_t>(args[4]);

            return to_string(m_processingLayer->CalculQualiteAirZone(
                latitude, longitude, radius, start, end));
        },
        {Argument("Latitude du centre : ", DOUBLE),
         Argument("Longitude du centre : ", DOUBLE),
         Argument("Rayon (km)", DOUBLE),
         Argument("Date de début (AAAA-MM-JJ)", DATE),
         Argument("Date de fin (AAAA-MM-JJ)", DATE)});

    AddAccess(ADMIN, moyenneZoneMenuItem);
}

const MenuItem&
AuthentificationLayer::AddMenuItem(const std::string& desc, MenuFunction func,
                                   std::initializer_list<Argument> args) {
    m_menus.emplace_front(desc, func, args);
    return m_menus.front();
}

void AuthentificationLayer::AddAccess(UserType user, const MenuItem& menu) {
    m_access[user].push_back(&menu);
}

const Menu& AuthentificationLayer::GetMenu(UserType user) {
    return m_access[user];
}
