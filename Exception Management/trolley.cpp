#include "trolley.h"

using namespace std;

trolley::trolley()
{

}
trolley::~trolley()
{

}
trolley::trolley(string name)
{
	this->name=name;
	speed=0;
}
int trolley::getSpeed()
{
	return speed;
}
void trolley::increaseSpeed(int s)
{
	speed+=s;
}