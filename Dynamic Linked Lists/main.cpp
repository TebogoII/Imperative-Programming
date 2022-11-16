#include "DynamicList.h"
#include "DynamicList.cpp"

#include <iostream>

using namespace std;

int main()
{
	/*Node<int> *n= new Node<int>(9);
	DynamicList<int> list;
	DynamicList<int> list2;
	list+=5;
	list+=23;
	list+=16;
	list2+=list;
	list2+=2;
	cout<<"same?: "<<(list2==list)<<endl;
	//cout<<"Approved? "<<list.insertNodeAt(2,4)<<endl;
	cout<<"size:"<<list.getSize()<<endl;
	cout<<"list[]:"<<list[1]<<endl;
	cout<<list<<endl;
	cout<<list2.deleteNode(23)<<endl;
	cout<<list2<<endl;
	delete n;*/

	DynamicList<int> list;
	list+=5;
	list+=-6;
	list+=7;
	cout<<list<<endl;
	cout<<list.getSize()<<endl;
	DynamicList<int> list2;
	list2+=list;
	//list2+=8;
	cout<<list2[-3]<<endl;
	cout<<"Added? "<<list.insertNodeAt(2,21)<<endl;
	cout<<"deleted? "<<list.deleteNode(21)<<endl;
	cout<<"same?: "<<(list2==list)<<endl;
	cout<<list<<endl;
	DynamicList<int> list3;
	list3+=4;
	cout<<"deleted? "<<list3.deleteNode(4)<<endl;
	cout<<"size: "<<list3.getSize()<<endl;
	cout<<"Added? "<<list3.insertNodeAt(0,3)<<endl;
	cout<<list3<<endl;
	return 0;
}