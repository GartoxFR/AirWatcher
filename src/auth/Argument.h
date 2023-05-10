#pragma once

#include <string>

enum ArgumentType { INT, DOUBLE, STRING, DATE };

class Argument {
  public:
    Argument(const std::string& prompt, ArgumentType type)
        : m_prompt(prompt), m_type(type) {}

    const std::string& GetPrompt() const { return m_prompt; }
    ArgumentType GetType() const { return m_type; }

  private:
    std::string m_prompt;
    ArgumentType m_type;
};
