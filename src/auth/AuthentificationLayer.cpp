#include "AuthentificationLayer.h"

#include <iostream>
#include <sstream>

using namespace std;

AuthentificationLayer::AuthentificationLayer(ProcessingLayer* processingLayer)
    : m_processingLayer(processingLayer) {

    // todo

    const auto& sum_menu = AddMenuItem("Ajoute 2 entiers",
                                       [](auto args) -> string {
                                           int* a = (int*)args[0];
                                           int* b = (int*)args[1];
                                           int res = *a + *b;
                                           stringstream ss;
                                           ss << a << " + " << b << " = " << res
                                              << endl;

                                           return ss.str();
                                       },
                                       {Argument("A = ", ArgumentType::INT),
                                        Argument("B = ", ArgumentType::INT)});

    AddAccess(UserType::ADMIN, sum_menu);
    cout << m_menus.size() << endl;
}

const MenuItem&
AuthentificationLayer::AddMenuItem(const std::string& desc, MenuFunction func,
                                   std::initializer_list<Argument> args) {
    m_menus.emplace_back(desc, func, args);
    return m_menus.back();
}

void AuthentificationLayer::AddAccess(UserType user, const MenuItem& menu) {
    m_access[user].push_back(&menu);
}

const Menu& AuthentificationLayer::GetMenu(UserType user) {
    return m_access[user];
}
