#ifndef TRAIN_H
#define TRAIN_H
#include "trainCar.h"
#include <sstream>

using namespace std;

class train
{
private:
	trainCar* head;
	int size;
public:
	train(string config);
	~train();
	int calcTotalCost();
	void addCar(int newCost);
};

#endif