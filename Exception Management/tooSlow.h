#ifndef TOOSLOW_H
#define TOOSLOW_H
#include <exception>

class tooSlow: public std::exception
{
public:
	tooSlow()
	{

	}
	~tooSlow() throw()
	{

	}
	const char* what() const throw()
	{
		return "TOO SLOW";
	}
	
};

#endif