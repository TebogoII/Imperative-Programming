#include <iostream>
#include "tome.h"
using namespace std;

void TomeConstructorPositive()
{
    cout << "--- TomeConstructorPositive ---" << endl;
    //given
    
    //when
    tome* d = new tome("Distillation", "John");
    
    //then
    cout << d->getName() << " = " << "NAME" << endl;
    cout << d->getAuthor() << " = " << "AUTHOR" << endl;
    delete d;
    cout << "--- END --- "<< endl << endl;
}

void TomeConstructorPositive2()
{
    cout << "--- TomeConstructorPositive ---" << endl;
    //given
    string * list=new string[3];
    list[0]="apple";
    list[1]="eye of lizard";
    list[2]="poison";
    //when
    tome* d = new tome("Distillation",3,"John",list);
    
    //then
    cout << d->getName() << " = " << "NAME" << endl;
    cout << d->getAuthor() << " = " << "AUTHOR" << endl;
    cout << d->getSpell(1) << " = " << "SPELL 2" << endl;
    cout << d->getTomeSize() << " = " << "TOME SIZE" << endl;
    cout<<*d;
    string ing;
    ing="eye of charles";
    *d+ing;
    tome b=*d;
    *d-"apple";
    *d+"poiso";
    *d-"poison";
    *d+"apple";
    *d-"poiso";
    *d+"poison";
    cout<<*d;
    cout<<b;
    cout<<(*d>b)<<endl; //true
    cout<<(*d<b)<<endl; //false
    cout<<(*d==b)<<endl; //false
    //delete ing;
    delete [] list;
    delete d;
    cout << "--- END --- "<< endl << endl;
}

int main()
{	
	TomeConstructorPositive();
	TomeConstructorPositive2();
	return 0;	
}