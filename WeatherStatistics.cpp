#include "WeatherStatistics.hpp"
using namespace std;
WeatherStatistics::WeatherStatistics(){
  loadData();
}

void WeatherStatistics::loadData(){
  for(int year = 2012; year <= 2015; year++){
    //runs loop over years.
    //File name differs only with years

    //create a string stream to synthesize the file name
    ostringstream fNameStream;
    fNameStream << RESOURCE_PATH << "Environmental_Data_Deep_Moor_" << year << ".txt";
    string fName = fNameStream.str(); //create the string from the stream
    fstream filestream;
    filestream.open(fName); //open the file for reading
    cout << "Imported:" << fName << endl;
    string line;
    getline(filestream, line); //skip the 1st line i.e the header
    while(getline(filestream, line)){
      string date, time;
      double Air_Temp, Barometric_Press, Dew_Point, Relative_Humidity, Wind_Dir, Wind_Gust, Wind_Speed;
      istringstream buffer(line); // create a input string stream buffer
      buffer >> date >> time >> Air_Temp >> Barometric_Press >> Dew_Point >> Relative_Humidity >> Wind_Dir >> Wind_Gust >> Wind_Speed; // pull the info from line buffer to variables.

      //create the time to pressure map
      time_t dateTime = convertDateTime(date, time);
      m_timeToPressure[dateTime] = Barometric_Press;
    }
  }
}

time_t WeatherStatistics::convertDateTime(string date, string time){
  // work with date first
  int yyyy, mon, dd = 0;
  if(sscanf(date.c_str(), "%d_%d_%d", &yyyy, &mon, &dd) != 3){
    cerr << "Error with date calculations" << endl;
    return -1;
  }

  int hh, mm, ss = 0;
  if(sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss) != 3){
        cerr << "Error with time calculations" << endl;
        return -1;
  }

  struct tm dt = {};
  dt.tm_year = yyyy - 1900;
  dt.tm_mon = mon;
  dt.tm_mday = dd;
  dt.tm_hour = hh;
  dt.tm_min = mm;
  dt.tm_sec = ss;

  return mktime(&dt);
}

double WeatherStatistics::computeCoefficient(string sDate, string sTime, string eDate, string eTime){

  //compute start and end times
  time_t start, end;
  start = convertDateTime(sDate, sTime);
  end = convertDateTime(eDate, eTime);

  //pull information from map
  //get iterators for times
  map<time_t, double>::iterator stIter;
  map<time_t, double>::iterator endIter;

  stIter = m_timeToPressure.lower_bound(start);
  endIter = m_timeToPressure.lower_bound(end);

  double timeDiff = endIter->first - stIter->first;
  double pressDiff = endIter->second - stIter->second;

  return (pressDiff / timeDiff);
  }