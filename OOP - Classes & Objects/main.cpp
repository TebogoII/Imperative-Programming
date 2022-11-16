#include <iostream>
#include "drone.h"
#include "factory.h"
#include <string>
using namespace std;

int main()
{
	drone ** griselda=new drone*[4];
	griselda[0]=new drone("Westside","Air",11,27.38);
	griselda[2]=new drone("Benny","Tank",9,20.38);
	griselda[3]=new drone("Conway","Tank",10,17.38);
	griselda[0]->print();

	factory buffalo("Griselda","WSG",griselda,4,3);
	buffalo.levelUp();
	buffalo.levelUp();
	factory testing("Test","firstly",8);
	testing.printDrones("hp");

	drone * newArtist=new drone("Armani","Air",8,1.38);

	cout<<buffalo.addDrone(newArtist)<<endl;
	cout<<buffalo.addDrone(newArtist)<<endl;
	cout<<buffalo.getFID()<<endl;
	cout<<buffalo.getOID()<<endl;
	cout<<buffalo.getCurrSize()<<endl;
	cout<<buffalo.getLimit()<<endl<<endl;
    buffalo.printDrones("m");
    cout<<endl<<endl;


    cout<<buffalo.removeDrone("Armani")<<endl;
    cout<<buffalo.removeDrone("Armani")<<endl;
	delete newArtist;
	delete griselda[1];
	delete griselda[2];
	delete griselda[3];
	delete [] griselda;

	return 0;
}