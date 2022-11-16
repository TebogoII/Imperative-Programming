#include "DynamicList.h"
using namespace std;

template <class T>
DynamicList<T>::DynamicList()
{
	head=NULL;
}

template <class T>
DynamicList<T>::~DynamicList()
{
	Node<T> *temp, *current;
	if (head!=NULL)
	{
		current=head->next;
		while(current!=head)
		{
			//cout<<*current->value<<endl;
			temp=current->next;
			delete current;
			current=temp;
		}
		delete head;
		head=NULL;
	}
}

template <class T>
Node<T>* DynamicList<T>::getHeadNode()
{
	return head;
}

template <class T>
T DynamicList<T>::operator[](const int index)
{
	if (head==NULL or index<0)
	{
		return -1;
	}
	Node<T>* newNode=head;
	for (int i = 0; i < index; ++i)
	{
		newNode=newNode->next;
	}
	return *newNode->value;
}

template <class T>
bool DynamicList<T>::deleteNode(T val)
{
	if (head==NULL)//empty
	{
		return false;
	}
	Node<T>* current=head, *prev=NULL;
	while (*current->value!=val)
	{
		if (current->next==head)
		{
			return false; //not found
		}
		prev=current;
		current=current->next;
	}

	//CHECK if only 1 node
	if (current->next==head && prev==NULL)
	{
		head=NULL;
		delete current;
		return true;
	}

	//more than 1
	if (current==head)//check if first
	{
		//cout<<"here";
		prev = head=head->prev;//move prev to last node
        head = current->next; //move head up
        prev->next = head;
        head->prev=  prev;
        delete current;
        return true;
	}
	//check if last
	else if (current->next==head)
	{
		prev->next=head;
		head->prev=prev;
		delete current;
        return true;
	}
	else
	{
		Node<T>* temp=current->next;//point to next
		prev->next=temp;
		temp->prev=prev;
		delete current;
        return true;
	}
}

template <class T>
bool DynamicList<T>::insertNodeAt(const int index,const T val)
{
	if (head!=NULL)
	{
		Node<T>* newNode=new Node<T>(val);
		Node<T>* current=head;
		if (0<=index && index<=getSize())
		{
			if (index==0)
			{
				while (current->next!=head)
				{
					current=current->next;
				}
				current->next=newNode;
				head->prev=newNode;
				newNode->next=head;
				newNode->prev=current;
				head=newNode;
			}
			else if (index==getSize())
			{
				*this+=val;
			}
			else
			{
				for (int i = 0; i < index-1; ++i)
				{
					//cout<<"--->"<<*current->value<<endl;
					current=current->next;
				}
				newNode->next=current->next;
				current->next->prev=newNode;
				newNode->prev=current;
				current->next=newNode;
			}
			return true;
		}
		else
		{
			delete newNode;
			return false;
		}
	}
	else
	{
		*this+=val;
		return true;
	}
}

template <class T>
bool DynamicList<T>::operator==(const DynamicList<T>& list)
{
	int size=list.getSize();
	Node<T>* current=head;
	Node<T>* listNode=list.head;
	if (this->head==NULL && list.head==NULL)
	{
		return true;
	}
	else
	{
		if (getSize()==size)
		{
			bool same=true;
			while (current->next!=this->head)
			{
				if (*current->value!=*listNode->value)
				{
					same=false;
				}
				current=current->next;
				listNode=listNode->next;
			}
			return same;
		}
		else
		{
			return false;
		}
	}
}

template <class T>
int DynamicList<T>::getSize() const
{
	if (head==NULL)
	{
		return 0;
	}
	if (head->next==head)
	{
		return 1;
	}
	Node<T>* ptr=head->next;
	int size=1;

	do
	{
		size++;
		ptr=ptr->next;
	}
	while (head!=ptr);
	return size;
}

template <class T>
ostream& operator<<(ostream& output, const DynamicList<T>& list)
{
	if (list.head==NULL)
	{
		return output;
	}
	Node<T>* current=list.head;

	for (int i = 0; i < list.getSize(); ++i)
	{
		output<<*current->value<<"["<<*current->prev->value<<","<<*current->next->value<<"]";
		if (current->next!=list.head)
		{
			output<<" -> ";
		}
		current=current->next;
	}
	return output;
}

template <class T>
void DynamicList<T>::operator+=(const DynamicList<T>& list)
{
	Node<T>* newNode=list.head;
	int size=list.getSize();
	for (int i = 0; i < size; ++i)
	{
		//cout<<"-->"<<list.getSize()<<endl;
		*this+=*newNode->value;
		newNode=newNode->next;
	}
}

template <class T>
void DynamicList<T>::operator+=(const T val)
{
	//cout<<"got here as"<<val<<endl;
	Node<T>* newNode=new Node<T>(val);
	if (head==NULL)
	{
		head=newNode;
		newNode->next=head;
		newNode->prev=head;
	}
	else
	{
		Node<T>* temp=head;
		while (temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next= newNode;
		newNode->next=head;
		newNode->prev=temp;
		head->prev=newNode;
	}
}