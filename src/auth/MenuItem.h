#pragma once

#include <any>
#include <functional>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

#include "../ui/Printable.h"
#include "Argument.h"

typedef std::function<std::string(const std::vector<std::any>&)> MenuFunction;

class MenuItem {
  public:
    MenuItem(const std::string& desc, const MenuFunction& func,
             std::initializer_list<Argument> args)
        : m_desc(desc), m_func(func), m_args(args) {}

    const std::string& GetDesc() const { return m_desc; }
    const std::vector<Argument>& GetArgs() const { return m_args; }

    std::string Call(const std::vector<std::any>& args) const;

  private:
    std::string m_desc;
    MenuFunction m_func;
    std::vector<Argument> m_args;
};
