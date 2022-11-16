#include "cargo.h"

cargo::cargo(char type,double weight,double cost, int powerDrain, int cargoCapacity): component(type, weight, cost, powerDrain)
{
	this->cargoCapacity=cargoCapacity;
}

int cargo::getCargoCapacity()
{
	return cargoCapacity;
}

cargo::~cargo()
{
	
}

double cargo::calculateEfficiency()
{
	double drain=component::getPowerDrain();
	return ((component::getWeight()+cargoCapacity)/drain)/component::getCost();
}