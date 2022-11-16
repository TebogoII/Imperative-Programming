#include "locomotive.h"

locomotive::locomotive(char type,double weight,double cost, int powerDrain, int powerGen): component(type, weight, cost, powerDrain)
{
	this->powerGen=powerGen;
}

int locomotive::getPowerGen()
{
	return powerGen;
}

locomotive::~locomotive()
{

}

double locomotive::calculateEfficiency()
{
	double drain=component::getPowerDrain();
	return ((powerGen/drain)/component::getCost());
}