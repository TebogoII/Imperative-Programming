#ifndef TRAINCAR_H
#define TRAINCAR_H
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class trainCar
{
private:
	int cost;
public:
	trainCar* next;
	trainCar(int c);
	~trainCar();
	int getCost();
};

#endif