#include "manager.h"

using namespace std;

template <class T>
manager<T>::manager(string input)
{
	int iPos;
	string line;
	string name;
	int count=0;
	ifstream datafile (input.c_str());
	if (datafile.is_open())
	{	
		getline(datafile,name);
		stringstream v(name);
		v>>numTrains;
		//cout<<numTrains<<endl;
		trains= new train<T>*[numTrains];
		while(datafile.good())
		{
			string x;
			getline(datafile,x);
			stringstream ss(x);
			getline(ss,line,',');

			//cout<<line<<endl;
			int cargoCap;
			
			iPos=x.find(",");
			x.erase(0,iPos+1);
			stringstream sss(x);
			sss>>cargoCap;
			//cout<<cargoCap<<endl;
			trains[count]=new train<T>(line,cargoCap);
			count++;
		}
	}
	datafile.close();
}

template <class T>
manager<T>::~manager()
{
	for (int i = 0; i < numTrains; ++i)
	{
		if (trains[i]!=NULL)
		delete trains[i];
	}
	delete [] trains;
}

template <class T>
void manager<T>::summarise()
{
	int total=0;
	for (int i = 0; i < numTrains; ++i)
	{
		if (trains[i]!=NULL)
		total+=trains[i]->getCurrCargo();
	}
	cout<<"Total Current Storage: "<<total<<endl;
}

template <class T>
void manager<T>::loadTrain(int i, T load)
{
	trains[i]->loadCargo(load);
}