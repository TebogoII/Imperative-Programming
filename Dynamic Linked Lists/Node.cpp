#include "Node.h"

using namespace std;
template <class T>
Node<T>::Node(T val)
{
	prev=NULL;
	next=NULL;
	value=new T;
	*value=val;
}

template <class T>
Node<T>::~Node()
{
	delete value;
}