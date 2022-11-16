#ifndef TRAIN_H
#define TRAIN_H
#include "component.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

class train;
std::ostream& operator<<(std::ostream& output, const train& t);

class train
{
private:
	component** design;
	int trainSize;
public:
	train(int size);
	~train();
	friend std::ostream& operator<<(std::ostream& output, const train& t);
	int addComponent(std::string comp);
	int removeComponent();
};
#endif