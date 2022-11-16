#ifndef STORAGEFULL_H
#define STORAGEFULL_H
#include <exception>

class storageFull: public std::exception
{
public:
	storageFull()
	{

	}
	~storageFull() throw()
	{

	}
	const char* what() const throw()
	{
		return "STORAGE FULL";
	}
	
};

#endif