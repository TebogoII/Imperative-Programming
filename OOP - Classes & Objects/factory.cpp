#include "factory.h"
#include "drone.h"
#include <string>
#include <iostream>

using namespace std;

factory::factory(string fID2, string oID2, int droneLimit2)
{
	fID=fID2;
	oID=oID2;
	droneLimit=droneLimit2;
	currNumDrones=0;
	level=1;
	list=new drone*[droneLimit];
}

factory::factory(string fID2, string oID2, drone** drones, int droneLimit2, int currNumDrones2)
{
	fID=fID2;
	oID=oID2;
	level=1;
	currNumDrones=currNumDrones2;
	droneLimit=droneLimit2;
	list=new drone*[droneLimit];
	for (int i = 0; i < droneLimit; ++i)
	{
		if (drones[i]!=0)
			list[i]=new drone(drones[i]->getName(),drones[i]->getType(),drones[i]->getHP(),drones[i]->getEnergy());
		else
			list[i]=0;
	}
}

factory::~factory()
{
	for (int i = 0; i < droneLimit; ++i)
	{
		if (list[i]!=0)
		delete list[i];
	}
	delete [] list;
}

void factory::levelUp()
{
	level++;
}

int factory::addDrone(drone* d)
{
	if (droneLimit!=currNumDrones)
	{
		for (int i = 0; i < droneLimit; ++i)
		{
			if (list[i]==0)
			{
					list[i]=new drone(d->getName(),d->getType(),level*(d->getHP()),level*(d->getEnergy()));
					currNumDrones++;
					return i;	
			}
		}
	}
	else
	{
		return -1;
	}	
	return -1;
}

int factory::removeDrone(string name)
{
	//cout<<"y"<<endl;
	for (int i = 0; i < droneLimit; ++i)
	{
		if (list[i]!=0)
		if (list[i]->getName()==name)
		{
			delete list[i];
			list[i]=0;
			currNumDrones--;
			return i;	
		}
		else
		{	
			if (i==droneLimit-1)
			{
				return -1;
			}
		}	
	}
	return -1;
}

string factory::getFID()
{
	return fID;
}

string factory::getOID()
{
	return oID;
}

int factory::getCurrSize()
{
	return currNumDrones;
}

int factory::getLimit()
{
	return droneLimit;
}

void factory::printDrones(string s)
{
	string sRank="";
	for (int i = 0; i < level; ++i)
	{
		sRank=sRank+"*";
	}
	double tEnergy=0;

	for (int i = 0; i < droneLimit; ++i)
	{
		if (list[i]!=0)
		{
			tEnergy=tEnergy+list[i]->getEnergy();
		}
	}

	cout<<"Factory ID: "<<fID<<endl;
	cout<<"OID: "<<oID<<endl;
	cout<<"Number of Drones: "<<currNumDrones<<endl;
	cout<<"Drone Limit: "<<droneLimit<<endl;
	cout<<"Rank: "<<sRank<<endl;
	if (currNumDrones!=0) 
		cout<<"Energy Level: "<<tEnergy<<endl;


	int low, hi;
	low=9999;
	hi=0;

	if (s=="hp")
	{
		//find highest hp
		for (int i = 0; i < droneLimit; ++i)
		{
			if (list[i]!=0)
			{
				if (list[i]->getHP()>hi)
				{
					hi=list[i]->getHP();
				}
			}
		}

		//print list
		for (int i = 0; i < hi+1; ++i)
		{
			for (int j = 0; j < droneLimit; ++j)
			{
				if (list[j]!=0)
				{		
					if (list[j]->getHP()==i)
					{
						cout<<list[j]->getName()<<endl;
					}
				}
			}
				
		}

		
	}
	else
	{
		//find lowest energy
		for (int i = 0; i < droneLimit; ++i)
		{
			if (list[i]!=0)
			{
				if (int(list[i]->getEnergy())<low)
				{
					low=int(list[i]->getEnergy());
				}
			}
		}
		hi=0;
		//highest energy
		for (int i = 0; i < droneLimit; ++i)
		{
			if (list[i]!=0)
			{
				if (int(list[i]->getEnergy())>hi)
				{
					hi=int(list[i]->getEnergy());
				}
			}
		}

		//cout<<low<<endl;
		//print list
		for (int i = hi+1; i > low-1; --i)
		{
			for (int j = 0; j < droneLimit; ++j)
			{
				if (list[j]!=0)
				{		
					
					if (int(list[j]->getEnergy())==i)
					{
						cout<<list[j]->getName()<<endl;
					}
				}
			}
				
		}		
	}
}