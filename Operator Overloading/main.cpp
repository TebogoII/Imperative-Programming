#include "cauldron.h"
#include "ingredient.h"
#include <string>
#include <iostream>

using namespace std;

void CopyCaulpos()
{
	cout<<"--COPY OPERATOR--"<<endl<<endl;
	//GIVEN
	cauldron *box=new cauldron("list.txt",3);
	cauldron *mix=new cauldron("list.txt",6);
	//WHEN
	*mix=*box;

	//THEN
	box->removeIngredient(0);
	delete box;
	cout<<mix->getIngredient(0)->getName()<<endl<<endl;
	delete mix;
	cout<<"--END--"<<endl<<endl;
}

void CopyCaul2pos()
{
	cout<<"--COPY CONSTRUCTOR--"<<endl<<endl;
	//GIVEN
	cauldron *mix=new cauldron("list.txt",6);
	cauldron *pack= new cauldron(mix);
	//WHEN
	mix->removeIngredient(0);
	//THEN
	cout<<pack->getIngredient(0)->getName()<<endl<<endl;
	delete pack;
	cout<<"--END--"<<endl<<endl;
	delete mix;
}

void copyIngpos()
{
	cout<<"--COPY INGREDIENT--"<<endl<<endl;
	//given
	ingredient *fruit=new ingredient("banana",8);

	//when
	ingredient *edible=new ingredient(fruit);

	//then
	delete fruit;
	cout<<edible->getName()<<endl;
	delete edible;
	cout<<"--END--"<<endl<<endl;
}

void addIngpos()
{
	cout<<"--ADD INGREDIENT--"<<endl<<endl;
	//given
	cauldron *box=new cauldron("list.txt",3);
	//when
	box->addIngredient("banana",8);
	//then
	cout<<box->getIngredient(3)->getName()<<endl;
	delete box;
	cout<<"--END--"<<endl<<endl;
}

void remIngpos()
{
	cout<<"--REMOVE INGREDIENT--"<<endl<<endl;
	//given
	cauldron *mix=new cauldron("list.txt",6);
	mix->listIngredients();
	//when
	mix->removeIngredient(0);
	//then
	mix->listIngredients();
	delete mix;
	cout<<"--END--"<<endl<<endl;
}

void distill()
{
	cout<<"--DISTILL--"<<endl<<endl;
	//given
	cauldron *mix=new cauldron("list.txt",6);
	cauldron *pack= new cauldron(mix);
	string * list=new string[2];
	list[0]="berry";
	list[1]="banana";
	mix->listIngredients();
	cout<<endl;
	//when
	pack->distillPotion(*mix,list,2);
	//then
	mix->listIngredients();
	delete [] list;
	delete mix;
	delete pack;
	cout<<endl<<"--END--"<<endl<<endl;
}

void CopyCaulneg()
{
	cout<<"--COPY OPERATOR NEG--"<<endl<<endl;
	//GIVEN
	cauldron *box=0;
	cauldron *mix=new cauldron("list.txt",6);
	//WHEN
	*mix=*box;
	//cout<<"i"<<endl;

	//THEN
	box->removeIngredient(0);
	//delete box;
	cout<<mix->getIngredient(0)->getName()<<endl<<endl;
	delete mix;
	cout<<"--END--"<<endl<<endl;
}

void CopyCaul2neg()
{
	cout<<"--COPY CONSTRUCTOR NEG--"<<endl<<endl;
	//GIVEN
	cauldron *mix=new cauldron("list.txt",6);
	cauldron *pack= new cauldron(mix);
	//WHEN
	mix->removeIngredient(-1);
	//THEN
	cout<<pack->getIngredient(0)->getName()<<endl<<endl;
	delete pack;
	cout<<"--END--"<<endl<<endl;
	delete mix;
}

void copyIngneg()
{
	cout<<"--COPY INGREDIENT NEG--"<<endl<<endl;
	//given
	ingredient *fruit=0;

	//when
	ingredient *edible=new ingredient(fruit);

	//then
	//delete fruit;
	cout<<edible->getName()<<endl;
	delete edible;
	cout<<"--END--"<<endl<<endl;
}

void addIngneg()
{
	cout<<"--ADD INGREDIENT NEG--"<<endl<<endl;
	//given
	cauldron *box=new cauldron("list.txt",3);
	//when
	box->addIngredient("banana",-1);
	//then
	cout<<box->getIngredient(3)->getName()<<endl;
	delete box;
	cout<<"--END--"<<endl<<endl;
}

void remIngneg()
{
	cout<<"--REMOVE INGREDIENT NEG--"<<endl<<endl;
	//given
	cauldron *mix=new cauldron("list.txt",6);
	mix->listIngredients();
	//when
	mix->removeIngredient(6);
	//then
	mix->listIngredients();
	delete mix;
	cout<<"--END--"<<endl<<endl;
}

void distillneg()
{
	cout<<"--DISTILL NEG--"<<endl<<endl;
	//given
	cauldron *pack=new cauldron("list.txt",6);
	cauldron *mix= new cauldron(pack);

	//delete pack;
	//pack=0;
	string * list=new string[2];
	list[0]="berry";
	list[1]="banana";
	mix->listIngredients();
	cout<<endl;
	//when
	mix->distillPotion(*pack,list,9);
	//then
	mix->listIngredients();
	delete [] list;
	delete mix;
	cout<<endl<<"--END--"<<endl<<endl;
}

void deepCopy()
{
	cout<<"--DEEP COPY--"<<endl<<endl;
	cauldron *pack=new cauldron("list.txt",6);
	cauldron *mix= new cauldron(pack);
	pack->removeIngredient(2);
	//test deep copy pack.Ingredient[2] was removed but should be in mix still
	if (mix->getIngredient(2)!=pack->getIngredient(2))
	{
		cout<<"deep copy successful"<<endl;
	}
	else
	{
		cout<<"deep copy unsuccessful"<<endl;
	}

	cout<<endl<<"--END--"<<endl<<endl;
}

int main()
{
	CopyCaulpos();
	CopyCaul2pos();
	addIngpos();
	remIngpos();
	distill();
	CopyCaulneg();
	CopyCaul2neg();
	addIngneg();
	remIngneg();
	distillneg();
	deepCopy();
}