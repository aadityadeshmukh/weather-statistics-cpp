#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctime>

#define RESOURCE_PATH "data/"
class WeatherStatistics{
  public:
  WeatherStatistics();
  private:
    void loadData();
    std::map<time_t, double> m_timeToPressure;
};