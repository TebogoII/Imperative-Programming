#include "train.h"
#include "storageEmpty.h"
#include "storageFull.h"
#include <iostream>

using namespace std;

template <class T>
train<T>::train()
{

}

template <class T>
train<T>::~train()
{
	cout<<"Dispatch Name: "<<name<<endl;
	cout<<"Current Storage: "<<currStorage<<endl;
	cout<<"Storage Max: "<<storageCap<<endl;
}

template <class T>
train<T>::train(string name,T storageCap)
{
	this->name=name;
	this->storageCap=storageCap;
	currStorage=0;
}

template <class T>
string train<T>::getName()
{
	return name;
}

template <class T>
T train<T>::getCargoCap()
{
	return storageCap;
}

template <class T>
T train<T>::getCurrCargo()
{
	return currStorage;
}

template <class T>
void train<T>::loadCargo(T cargo)
{
	storageFull ex;
	if (cargo+this->currStorage>storageCap)
	{
		throw ex;
	}
	else
	{
		currStorage=cargo+currStorage;
		cout<<"Capacity: "<<currStorage<<endl;
	}
}

template <class T>
void train<T>::unloadCargo(T cargo)
{
	storageEmpty ex;
	if (currStorage-cargo<0)
	{
		throw ex;
	}
	else
	{
		currStorage=currStorage-cargo;
		cout<<"Capacity: "<<currStorage<<endl;
	}
}