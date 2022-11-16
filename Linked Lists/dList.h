#ifndef DLIST_H
#define DLIST_H
#include "train.h"
#include "trainCar.h"
#include "dispatch.h"
#include <cstdlib>
#include <iostream>
#include <string>

class dList;
ostream& operator<<(ostream& output,const dList& dlist);
using namespace std;

class dList
{
private:
	dispatch* head;
	int size;
	int rS;
public:
	dList(int rS);
	~dList();
	dispatch* getHead() const;
	int getSize() const;
	dispatch* getItem(int i);
	string firstOrder();
	friend ostream& operator<<(ostream& output,const dList& dlist);
	void addOrder(string newOrder);
	void validateTrain();
	void shuffleOrders();
};

#endif