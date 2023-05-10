#include <vector>
#include <Cleaner.h>

typedef std::vector<Cleaner*>
    CleanerVector;

class Provider {
  public:
    Provider(std::string providerId)
        : m_providerId(providerId) {}

    std::string GetProviderId() const { return m_providerId; }
    CleanerVector GetCleaners() const { return m_cleaners; }

  private:
    std::string m_providerId;
    CleanerVector m_cleaners;
};