#include "dispatch.h"

dispatch::dispatch(string o)
{
	next=NULL;
	order=o;
}
dispatch::~dispatch()
{
	cout<<order<<" processed"<<endl;
}
string dispatch::getOrder()
{
	return order;
}