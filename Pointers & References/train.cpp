#include "train.h"
#include "locomotive.h"
#include "cargo.h"
#include "passenger.h"
using namespace std;

train::train(int size)
{
	trainSize=size;
	design=new component*[size];
	for (int i = 0; i < size; ++i)
	{
		design[i]=NULL;
	}
}

train::~train()
{
	int car=0;
	int pas=0;
	int loc=0;
	for (int i = 0; i < trainSize; ++i)
	{
		if (design[i]!=NULL)
		{
			if (design[i]->getType()=='c')
			{
				car++;
			}
			else if (design[i]->getType()=='p')
			{
				pas++;
			}
			else if (design[i]->getType()=='l')
			{
				loc++;
			}
			delete design[i];
		}
	}
	delete [] design;
	cout<<"Number of Cargo Cars: "<<car<<endl;
	cout<<"Number of Passenger Cars: "<<pas<<endl;
	cout<<"Number of Locomotives: "<<loc<<endl;
}

ostream& operator<<(ostream& output, const train& t)
{
	output<<"DESIGN: ";
	for (int i = 0; i < t.trainSize; ++i)
	{
		if (t.design[i]!=NULL)
		{
			output<<t.design[i]->getType();
		}
	}
	output<<endl;
	output<<"Efficiency Rating: ";
	double sum;
	for (int i = 0; i < t.trainSize; ++i)
	{
		if (t.design[i]!=NULL)
		{
			sum=sum+t.design[i]->calculateEfficiency();
		}
	}
	output<<sum<<endl;
	int car=0;
	int pas=0;
	int loc=0;
	for (int i = 0; i < t.trainSize; ++i)
	{
		if (t.design[i]!=NULL)
		{
			if (t.design[i]->getType()=='c')
			{
				car++;
			}
			else if (t.design[i]->getType()=='p')
			{
				pas++;
			}
			else if (t.design[i]->getType()=='l')
			{
				loc++;
			}
		}
	}
	output<<"Cargo Cars: "<<car<<endl;
	output<<"Passenger Cars: "<<pas<<endl;
	output<<"Locomotives: "<<loc<<endl;
	return output;
}

int train::addComponent(std::string comp)
{
	bool full=true;
	int pos;
	for (int i = 0; i < trainSize; ++i)
	{
		if (design[i]==NULL)
		{
			full=false;
			pos=i;
			break;
		}
	}
	if (full)
	{
		return -1;
	}

	stringstream ss(comp);
	string X,A,B,C,D;
	getline(ss,X,',');
	getline(ss,A,',');
	getline(ss,B,',');
	getline(ss,C,',');
	getline(ss,D,',');
	char type=X[0];
	//cout<<type<<endl;

	double weight;
	ss.clear();
	ss.str("");
	ss.str(A);
	ss>>weight;
	//cout<<weight<<endl;

	double cost;
	ss.clear();
	ss.str("");
	ss.str(B);
	ss>>cost;
	//cout<<cost<<endl;

	int powerDrain;
	ss.clear();
	ss.str("");
	ss.str(C);
	ss>>powerDrain;
	//cout<<powerDrain<<endl;

	int Cap;
	ss.clear();
	ss.str("");
	ss.str(D);
	ss>>Cap;
	//cout<<Cap<<endl;

	if (type=='c')
	{
		design[pos]=new cargo(type,weight,cost,powerDrain,Cap);
	}
	else if (type=='p')
	{
		design[pos]=new passenger(type,weight,cost,powerDrain,Cap);
	}
	else if (type=='l')
	{
		design[pos]=new locomotive(type,weight,cost,powerDrain,Cap);
	}
	return pos;
}

int train::removeComponent()
{
	for (int i = 0; i < trainSize; ++i)
	{
		if (design[i]!=NULL)
		{
			delete design[i];
			design[i]=NULL;
			return i;
		}
	}
	return -1;
}