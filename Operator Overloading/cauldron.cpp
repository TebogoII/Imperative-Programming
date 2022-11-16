#include "cauldron.h"
#include "ingredient.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

cauldron::cauldron(string ingredientList, int maxIngredients)
{
	ifstream datafile (ingredientList.c_str());
	stringstream ss;
	int y, iPos,dR;
	string sub,line;

	this->maxIngredients=maxIngredients;
	ingredients=new ingredient*[maxIngredients];
	for (int i = 0; i < maxIngredients; ++i)
	{
		ingredients[i]=NULL;
	}

	if (not datafile.fail())
	{
		if (datafile.is_open())
		{
			y=0;
			while(datafile.good())
			{
				getline(datafile,line);
				stringstream ss(line);
				getline(ss,sub,',');
				iPos=line.find(",");
				line.erase(0,iPos+1);
				stringstream danger(line);
				danger>>dR;
				ingredients[y]=new ingredient(sub,dR);
				//cout<<ingredients[y]->getName()<<":"<<ingredients[y]->getDanger()<<endl;
				y++;
				if (y==maxIngredients)
				{
					break;
				}
			}
			numIngredients=y;
		}
	}
	else
	{

	}
	datafile.close();
}

cauldron::cauldron(const cauldron* oldCauldron)
{	
	if (this==oldCauldron)
	{
		
	}
	else if (oldCauldron!=NULL)
	{
		numIngredients=oldCauldron->getCurr();
		maxIngredients=oldCauldron->getMax();
		//cout<<maxIngredients<<endl;
		ingredients=new ingredient*[maxIngredients];
		for (int i = 0; i < maxIngredients; ++i)
		{
			ingredients[i]=NULL;
		}
		int z=0;
		for (int i = 0; i < maxIngredients; ++i)
		{
			if (oldCauldron->getCurr()!=z)
			{
				ingredients[i]=new ingredient((oldCauldron->getIngredient(i))->getName(),(oldCauldron->getIngredient(i))->getDanger());
				z++;
			}
		}
	}
}

void cauldron::operator=(const cauldron& oldCauldron)
{
	//cout<<"working"<<endl;
	if (this==&oldCauldron)
	{
		
	}
	else if (&oldCauldron!=NULL)
	{
		for (int i = 0; i < maxIngredients; ++i)
		{
			if (ingredients[i]!=0)
			{ 
				//cout<<"ll"<<endl;
				//cout<<i<<" deleted because "<<ingredients[i]<<endl;
				delete ingredients[i];
			}
		}
		delete [] ingredients;
		this->numIngredients=oldCauldron.getCurr();
		this->maxIngredients=oldCauldron.getMax();
		//cout<<maxIngredients<<endl;
		ingredients=new ingredient*[maxIngredients];
		int z=0;
		for (int i = 0; i < maxIngredients; ++i)
		{
			if (oldCauldron.getCurr()!=z)
			{
				ingredients[i]=new ingredient((oldCauldron.getIngredient(i))->getName(),(oldCauldron.getIngredient(i))->getDanger());
				z++;
			}
		}
	}
}

cauldron::~cauldron()
{
	for (int i = 0; i < maxIngredients; ++i)
	{
		delete ingredients[i];
	}
	delete [] ingredients;
}

void cauldron::print()
{
	double avg,d;
	int min,max,sum;
	min=999;
	max=0;
	sum=0;

	for (int i = 0; i < maxIngredients; ++i)
	{
		if (ingredients[i]!=0)
		{
			sum=sum+ingredients[i]->getDanger();
			if (ingredients[i]->getDanger()<min)
			{
				min=ingredients[i]->getDanger();
			}
			if (ingredients[i]->getDanger()>max)
			{
				max=ingredients[i]->getDanger();
			}
		}
	}
	d=numIngredients;
	avg=sum/d;
	cout<<"Number of Ingredients: "<<numIngredients<<endl;
	cout<<"Average Danger Rating: "<<avg<<endl;
	cout<<"Maximum Danger Rating: "<<max<<endl;
	cout<<"Minimum Danger Rating: "<<min<<endl;
}

int cauldron::getMax() const
{
	return maxIngredients;
}
int cauldron::getCurr() const
{
	return numIngredients;
}

ingredient* cauldron::getIngredient(int a) const
{
	return ingredients[a];
}

int cauldron::addIngredient(string in, int dR)
{
	int iPos=0;
	if (numIngredients==maxIngredients)
	{
		//cout<<in<<" "<<dR<<" "<<maxIngredients<<endl;
		ingredient** tempo=new ingredient*[maxIngredients];
		for (int i = 0; i < maxIngredients; ++i)
		{
			if (ingredients[i]!=NULL)
			{
				//cout<<maxIngredients<<endl;
				tempo[i]=ingredients[i];
				//cout<<tempo[i]->getName()<<endl;
			}
		}

		delete [] ingredients;
		//cout<<"main"<<endl;
		ingredients=new ingredient*[maxIngredients+1];
		for (int i = 0; i < maxIngredients; ++i)
		{
			if (tempo[i]!=NULL)
			{	
				ingredients[i]=tempo[i];
				//cout<<ingredients[i]->getName()<<endl;
			}	
		}
		delete [] tempo;
		ingredients[maxIngredients]=new ingredient(in,dR);
		maxIngredients++;
		numIngredients++;
		//cout<<"on"<<endl;
		return maxIngredients;

	}
	else
	{
		for (int i = 0; i < maxIngredients; ++i)
		{
			if (ingredients[i]==NULL)
			{
				iPos=i;
				ingredients[i]=new ingredient(in,dR);
				numIngredients++;
				return i;
			}
		}
	}
	return iPos;
}

void cauldron::removeIngredient(int in)
{
	if (this!=0 and in>0)
	{
		//cout<<"i"<<endl;
		if (in<=maxIngredients)
		{	
			if (ingredients[in]!=NULL)
			{	
				//cout<<ingredients[in]->getName();
				delete ingredients[in];
				ingredients[in]=NULL;
				//cout<<" deleted"<<endl;
				numIngredients--;
			}	
		}	
	}
}

void cauldron::distillPotion(cauldron & currCauldron,string* list,int numRemove)
{
	bool inbound=1;
	if (numRemove>=0 and numRemove<=numIngredients);
	{	
		if (numRemove<=numIngredients)
		{
			/* code */
		}
		for (int j = 0; j < numRemove; ++j)
		{
			//cout<<"mm"<<endl;
			for (int i = 0; i < currCauldron.getMax(); ++i)
			{
				if (currCauldron.getIngredient(i)!=NULL)
				{	
					if (&list[j]!=NULL)
					{
						//cout<<list[j]<<endl;
						if (list[j]==currCauldron.getIngredient(i)->getName())
						{
							currCauldron.removeIngredient(i);
							//break;
						}
					}	
				}	
			}
		}
	}	
}

void cauldron::listIngredients()
{
	for (int i = 0; i < maxIngredients; ++i)
	{
		if (ingredients[i]!=NULL)
		{
			cout<<ingredients[i]->getName()<<endl;
		}
	}
}