#include "AuthentificationLayer.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

AuthentificationLayer::AuthentificationLayer(ProcessingLayer* processingLayer)
    : m_processingLayer(processingLayer) {

    // todo

    m_menus.reserve(10);
    const auto& sum_menu = AddMenuItem("Ajoute 2 entiers",
                                       [](auto args) -> string {
                                           int a = any_cast<int>(args[0]);
                                           int b = any_cast<int>(args[1]);
                                           int res = a + b;
                                           stringstream ss;
                                           ss << a << " + " << b << " = " << res
                                              << endl;

                                           return ss.str();
                                       },
                                       {Argument("A = ", ArgumentType::INT),
                                        Argument("B = ", ArgumentType::INT)});
    const auto& d = AddMenuItem("Double un nombre",
                                [](auto args) -> string {
                                    int n = any_cast<int>(args[0]);
                                    n *= 2;
                                    return std::to_string(n);
                                },
                                {Argument("Nombre : ", ArgumentType::INT)});

    AddAccess(UserType::ADMIN, sum_menu);
    AddAccess(UserType::ADMIN, d);
}

const MenuItem&
AuthentificationLayer::AddMenuItem(const std::string& desc, MenuFunction func,
                                   std::initializer_list<Argument> args) {
    m_menus.emplace_back(desc, func, args);
    return m_menus[m_menus.size() - 1];
}

void AuthentificationLayer::AddAccess(UserType user, const MenuItem& menu) {
    m_access[user].push_back(&menu);
}

const Menu& AuthentificationLayer::GetMenu(UserType user) {
    return m_access[user];
}
