#ifndef CARGO_H
#define CARGO_H
#include "component.h"

class cargo: public component
{
private:
	int cargoCapacity;
public:
	cargo(char type,double weight,double cost, int powerDrain, int cargoCapacity);
	int getCargoCapacity();
	~cargo();
	double calculateEfficiency();
};

#endif