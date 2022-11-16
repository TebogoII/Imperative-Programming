#include "dList.h"

dList::dList(int rS)
{
	this->rS=rS;
	head=NULL;
	size=0;
}

dList::~dList()
{
	dispatch* node = head;
	while (node)
	{
		head=head->next;
		delete node;
		node=head;
	}
}

dispatch* dList::getHead() const
{
	return head;
}

int dList::getSize() const
{
	return size;
}

dispatch* dList::getItem(int i)
{
	if (i<0 or i>size)
	{
		return NULL;
	}
	if (i=0)
	{
		return head;
	}
	dispatch* node = head;
	for (int j = 0; j < i; ++i)
	{
		node=node->next;
	}
	return node;
}

string dList::firstOrder()
{
	dispatch* node = head;
	string first=node->getOrder();
	while (node)
	{
		if (node->getOrder()<first)
		{
			first=node->getOrder();
		}
		node=node->next;
	}
	return first;
}

ostream& operator<<(ostream& output,const dList& dlist)
{
	dispatch* node = dlist.head;
	for (int i = 0; i < dlist.getSize(); ++i)
	{
		output<<node->getOrder();
		if (node->next!=NULL )
		{
			output<<",";
		}
		node=node->next;
	}
	output<<endl;
	return output;
}

void dList::addOrder(string newOrder)
{
	dispatch* add=new dispatch(newOrder);
	dispatch* node = head;
	size++;
	if (head!=NULL)
	{
		if (add->getOrder()>this->firstOrder())
		{
			head=add;
			add->next=node;
		}
		else
		{
			while(node->next)
			{
				node=node->next;
			}
			node->next=add;
		}
	}
	else
	{
		head=add;
	}
}

void dList::validateTrain()
{
	if (head==NULL)
	{
		cout<<"Invalid"<<endl;
		return;
	}
	dispatch* node = head;
	train validate(node->getOrder());
	if (validate.calcTotalCost()<50)
	{
		cout<<"Valid"<<endl;
	}
	else
	{
		cout<<"Invalid"<<endl;
	}
	head=node->next;
	delete node;
	node=head;
}

void dList::shuffleOrders()
{
	dispatch* node=head;
	dispatch* prev;
	srand(rS);
	int num = rand() % size;
	dispatch* last=head;
	while(last->next)
	{
		last=last->next;
	}
	for (int i = 0; i < num; ++i)
	{
		head=node->next;
		node->next=NULL;
		last->next=node;
		last=node;
		node=head;
	}
}