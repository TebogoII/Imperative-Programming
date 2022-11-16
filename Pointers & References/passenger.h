#ifndef PASSENGER_H
#define PASSENGER_H
#include "component.h"

class passenger: public component
{
private:
	int passengerCapacity;
public:
	passenger(char type,double weight,double cost, int powerDrain, int passengerCapacity);
	int getPassengerCapacity();
	~passenger();
	double calculateEfficiency();
};

#endif