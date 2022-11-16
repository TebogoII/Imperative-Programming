#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include <sstream>
#include <fstream>
#include "train.h"

template <class T>
class manager
{
private:
	train<T>** trains;
	int numTrains;
public:
	manager(string input);
	~manager();
	void summarise();
	void loadTrain(int i, T load);
};

#endif