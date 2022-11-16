#include "passenger.h"

passenger::passenger(char type,double weight,double cost, int powerDrain, int passengerCapacity): component(type, weight, cost, powerDrain)
{
	this->passengerCapacity=passengerCapacity;
}

int passenger::getPassengerCapacity()
{
	return passengerCapacity;
}

passenger::~passenger()
{
	
}

double passenger::calculateEfficiency()
{
	double drain=component::getPowerDrain();
	return ((component::getWeight()*passengerCapacity)/drain)/component::getCost();
}