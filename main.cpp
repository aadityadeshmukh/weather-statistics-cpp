#include <iostream>
#include "WeatherStatistics.hpp"
using namespace std;
int main(){
  cout << "Hello!" << endl;
  WeatherStatistics w;

  string startDate, startTime;
  string endDate, endTime;
	cout << endl << "Enter START DATE as yyyy_mm_dd: ";
	cin >> startDate;
	cout << "Enter START TIME as hh:mm:ss (24-hour): ";
	cin >> startTime;

	cout << "Enter END DATE as yyyy_mm_dd: ";
	cin >> endDate;
	cout << "Enter END TIME as hh:mm:ss (24-hour): ";
	cin >> endTime; 

  double coeff = w.computeCoefficient(startDate, startTime, endDate, endTime);
  if(coeff < 0 )
  {
    cout << "It might rain. Take an umbrella" << endl;
  }
  else
    cout << "Sunny Weather! Carry sunscreen." << endl;
}