#include "train.h"

train::train(string config)
{
	string sub;
	size=1;
	int iPos=0;
	int cost;
	string line=config;
	stringstream ss(line);
	getline(ss,sub,',');
	stringstream h(sub);
	h>>cost;
	//cout<<"ke "<<cost<<endl;
	line.erase(0,iPos+1);
	head=new trainCar(cost);
	trainCar* node=head;
	//cout<<line<<endl;
	while (line.find(",")<line.length())
	{
		size++;
		stringstream con(line);
		getline(con,sub,',');
		con>>cost;
		//cout<<cost<<endl;
		node->next=new  trainCar(cost);
		node=node->next;
		iPos=line.find(",");
		line.erase(0,iPos+1);
	}
}

train::~train()
{
	trainCar* node=head;
	while (node)
	{
		head=head->next;
		delete node;
		node=head;
	}
}

int train::calcTotalCost()
{
	int sum=0;
	trainCar* node=head;
	while (node)
	{
		sum=sum+node->getCost();
		node=node->next;
	}
	cout<<"Total Train Cost: "<<sum<<endl;
	return sum;
}

void train::addCar(int newCost)
{
	trainCar* node=head;
	while (node->next)
	{
		node=node->next;
	}
	node->next=new trainCar(newCost);
	size++;
	//cout<<size<<endl;
}