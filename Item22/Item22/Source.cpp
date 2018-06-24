#include <stdlib.h>
#include <list>
#include <iostream>
#include <numeric>
#include "Header.h"



void SpeedDataCollection::addValue(int speed) 
{ 
	speedValues.push_back(speed);
	//average = average + (speed - average) / speedValues.size();
}

double SpeedDataCollection::averageSoFar() const 
{ 
	//return average; 

	double aver = (std::accumulate(speedValues.begin(), speedValues.end(), 0.0) / speedValues.size());

	return aver;
}


int main()
{
	SpeedDataCollection s;

	s.addValue(10);
	s.addValue(20);
	s.addValue(40);

	std::cout << s.averageSoFar() << "\n";

	system("pause");
}