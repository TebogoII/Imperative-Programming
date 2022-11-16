#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H
#include "component.h"

class locomotive: public component
{
private:
	int powerGen;
public:
	locomotive(char type,double weight,double cost, int powerDrain, int powerGen);
	int getPowerGen();

	~locomotive();
	double calculateEfficiency();
};

#endif