#ifndef STORAGEEMPTY_H
#define STORAGEEMPTY_H
#include <exception>

class storageEmpty: public std::exception
{
public:
	storageEmpty()
	{

	}
	~storageEmpty() throw()
	{

	}
	const char* what() const throw()
	{
		return "STORAGE EMPTY";
	}
	
};

#endif