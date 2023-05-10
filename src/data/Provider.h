#pragma once

#include <vector>
#include "Cleaner.h"

typedef std::vector<Cleaner*>
    CleanerPointerVector;

class Provider {
  public:
    Provider(std::string providerId)
        : m_providerId(providerId) {}

    std::string GetProviderId() const { return m_providerId; }
    CleanerPointerVector GetCleaners() const { return m_cleaners; }

  private:
    std::string m_providerId;
    CleanerPointerVector m_cleaners;
};