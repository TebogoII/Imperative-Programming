#include "drone.h"
#include <string>
#include <iostream>

using namespace std;

drone::drone(string name2, string type2, int hp2, double energy2)
{
	name=name2;
	type=type2;
	hp=hp2;
	energy=energy2;
}

drone::~drone()
{
	cout<<name<<" deleted"<<endl;
}

string drone::getName()
{
	return name;
}

string drone::getType()
{
	return type;
}

int drone::getHP()
{
	return hp;
}

double drone::getEnergy()
{
	return energy;
}

void drone::print()
{
	cout<<"Name: "<<name<<endl;
	cout<<"Type: "<<type<<endl;
	cout<<"HP: "<<hp<<endl;
	cout<<"Energy: "<<energy<<endl;
}