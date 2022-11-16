#include "trainCar.h"

trainCar::trainCar(int c)
{
	cost=c;
	next=NULL;
}
trainCar::~trainCar()
{
	cout<<cost<<" removed"<<endl;
}
int trainCar::getCost()
{
	return cost;
}