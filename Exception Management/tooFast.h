#ifndef TOOFAST_H
#define TOOFAST_H
#include <exception>

class tooFast: public std::exception
{
public:
	tooFast()
	{

	}
	~tooFast() throw()
	{

	}
	const char* what() const throw()
	{
		return "TOO FAST";
	}
	
};

#endif