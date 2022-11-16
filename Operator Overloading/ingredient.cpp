#include "ingredient.h"
#include <string>
using namespace std;

ingredient::ingredient(string name,int dangerRating)
{
	this->name=name;
	this->dangerRating=dangerRating;
}

ingredient::ingredient(const ingredient * newIngredient)
{
	ingredient &copier=const_cast<ingredient &>(*newIngredient);
	name=copier.getName();
	dangerRating=copier.getDanger();
}

ingredient::ingredient(const ingredient & newIngredient) 
{
	ingredient &copier=const_cast<ingredient &>(newIngredient);
	name=copier.getName();
	dangerRating=copier.getDanger();
}

ingredient::~ingredient()
{}

int ingredient::getDanger()
{
	return dangerRating;
}

string ingredient::getName()
{
	return name;
}