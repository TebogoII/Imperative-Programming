#ifndef TRAIN_H
#define TRAIN_H
#include <string>

template <class T>
class train
{
private:
	T currStorage;
	T storageCap;
	std::string name;
public:
	train();
	~train();
	train(std::string name,T storageCap);
	std::string getName();
	T getCargoCap();
	T getCurrCargo();
	void loadCargo(T cargo);
	void unloadCargo(T cargo);
};

#endif