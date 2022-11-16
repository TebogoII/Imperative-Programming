#include "train.h"
#include "train.cpp"
#include "trolley.h"
#include "manager.h"
#include "manager.cpp"

using namespace std;

int main()
{
	train<int> drive("Conductor Williams",5);
	try{
		drive.loadCargo(2);
		drive.unloadCargo(4);
	}
	catch(exception& ex)
	{
		cout<<ex.what()<<endl;
	}

	trolley box("troll");
	box.increaseSpeed(20);
	box.increaseSpeed(20);
	cout<<box.getSpeed()<<endl;

	manager<int> man("input.txt");
	man.summarise();
	man.loadTrain(0,3);
	try
	{
		man.loadTrain(1,299);
	}
	catch(exception& ex)
	{
		cout<<ex.what()<<endl;
	}
	return 0;
}