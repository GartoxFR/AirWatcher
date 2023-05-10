#include <string>
#include <Provider.h>

class Cleaner {
  public:
    Cleaner(std::string cleanerId, double latitude, double longitude, time_t start, time_t end)
        : m_cleanerId(cleanerId), m_latitude(latitude), m_longitude(longitude), m_start(start), m_end(end) {}

    const std::string& GetCleanerId() const { return m_cleanerId; }
    double GetLatitude() const { return m_latitude; }
    double GetLongitude() const { return m_longitude; }
    time_t GetStart() const { return m_start; }
    time_t GetEnd() const { return m_end; }
    Provider* GetProvider() const { return m_provider; }

  private:
    std::string m_cleanerId;
    double m_latitude;
    double m_longitude;
    time_t m_start;
    time_t m_end;
    Provider* m_provider;
};