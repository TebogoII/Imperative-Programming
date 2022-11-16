#include "component.h"
#include "locomotive.h"
#include "cargo.h"
#include "passenger.h"
#include "train.h"
#include <iostream>

using namespace std;

int main()
{
	locomotive cart('w',80.7,2.8,4,5);
	cargo bighold('w',80.7,2.8,4,8);
	passenger wing('w',80.7,2.8,4,24);
	train revolver(3);
	cout<<cart.calculateEfficiency()<<endl;
	cout<<bighold.calculateEfficiency()<<endl;
	cout<<wing.calculateEfficiency()<<endl;
	cout<<revolver.addComponent("c,90.1,775.1,14,1000")<<endl;
	cout<<revolver.addComponent("l,90.1,775.1,14,1000")<<endl;
	cout<<revolver.addComponent("l,90.1,775.1,14,1000")<<endl;
	cout<<revolver.addComponent("p,90.1,775.1,14,1000")<<endl;
	cout<<revolver;
	revolver.removeComponent();
	cout<<revolver;
	return 0;
}