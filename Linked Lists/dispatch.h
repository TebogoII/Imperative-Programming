#ifndef DISPATCH_H
#define DISPATCH_H
#include <iostream>
#include <string>

using namespace std;

class dispatch
{
private:
	string order;
public:
	dispatch* next;
	dispatch(string o);
	~dispatch();
	string getOrder();
};

#endif