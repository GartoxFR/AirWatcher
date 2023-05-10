#pragma once

#include "../processing/ProcessingLayer.h"
#include "MenuItem.h"
#include <initializer_list>
#include <map>
#include <vector>

enum UserType { ADMIN, GOUV, USER, PROVIDER };

typedef std::vector<const MenuItem*> Menu;
typedef std::map<UserType, Menu> UserMenus;
typedef std::vector<MenuItem> MenuList;

class AuthentificationLayer {
  public:
    AuthentificationLayer(ProcessingLayer* processingLayer);

    const MenuItem& AddMenuItem(const std::string& desc, MenuFunction func,
                                std::initializer_list<Argument> args);

    void AddAccess(UserType user, const MenuItem& menu);

    const Menu& GetMenu(UserType user);

  private:
    MenuList m_menus;
    UserMenus m_access;
    ProcessingLayer* m_processingLayer;
};
