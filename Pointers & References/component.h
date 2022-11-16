#ifndef COMPONENT_H
#define COMPONENT_H

class component
{
private:
	double weight;
	int powerDrain;
	double cost;
	char type;
public:
	component();
	component(char type,double weight,double cost, int powerDrain);
	double getWeight();
	double getCost();
	int getPowerDrain();
	char getType();
	virtual ~component();
	virtual double calculateEfficiency();
};
#endif