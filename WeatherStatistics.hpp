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
  double computeCoefficient(std::string sDate, std::string sTime, std::string eDate, std::string eTime);
  bool isDateTimeValid(std::string iDate, std::string iTime);
  private:
    void loadData();
    time_t convertDateTime(std::string date, std::string time);
    std::map<time_t, double> m_timeToPressure;
};