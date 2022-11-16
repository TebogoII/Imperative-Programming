#ifndef FACTORY_H
#define FACTORY_H
#include "drone.h"
#include <string>
using namespace std;

class factory
{
private:
	drone ** list;
	string fID;
	string oID;
	int level;
	int droneLimit;
	int currNumDrones;
public:
	factory(string fID2, string oID2, int droneLimit2);
	factory(string fID2, string oID2, drone** drones, int droneLimit2, int currNumDrones2);
	~factory();
	void levelUp();
	int addDrone(drone* d);
	int removeDrone(string name);
	string getFID();
	string getOID();
	int getCurrSize();
	int getLimit();
	void printDrones(string s);
};
#endif