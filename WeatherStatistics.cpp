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
    }
  }
}