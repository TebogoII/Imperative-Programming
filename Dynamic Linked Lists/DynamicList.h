#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H
#include "Node.cpp"

#include <cstddef>
#include <iostream>

template <class T>
class DynamicList;
template <class T>
std::ostream& operator<<(std::ostream& output, const DynamicList<T>& list);

template <class T>
class DynamicList
{
private:
	Node<T>* head;
public:
	DynamicList();
	~DynamicList();
	Node<T>* getHeadNode();
	T operator[](const int index);
	bool deleteNode(T val);
	bool insertNodeAt(const int index,const T val);
	bool operator==(const DynamicList<T>& list);
	int getSize() const;
	friend std::ostream& operator<<<T>(std::ostream& output, const DynamicList<T>& list);
	void operator+=(const DynamicList<T>& list);
	void operator+=(const T val);
};
#endif