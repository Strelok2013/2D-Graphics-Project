#include "TestingZone.h"


void TestingClass::TestFunc()
{
}



ConstructorDemo::ConstructorDemo()
{
	// Default Constructor
	std::cout << "Default Constructor Called" << std::endl;

}

ConstructorDemo::~ConstructorDemo()
{
	// Destructor
	std::cout << "Destructor called" << std::endl;

}

ConstructorDemo::ConstructorDemo(const ConstructorDemo& other)
{
	// Copy constructor
	//this.something = other.something;
	std::cout << "Copy constructor called" << std::endl;
}

ConstructorDemo::ConstructorDemo(ConstructorDemo&& other)
{
	// Move constructor
	//this.something = other.something
	//other.something = null
	std::cout << "Move constructor called" << std::endl;
	if (&other == this)
	{
		return;
	}
	// Move operations happen here
	
}

ConstructorDemo& ConstructorDemo::operator=(const ConstructorDemo& other)
{
	// Assignment operator
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

ConstructorDemo& ConstructorDemo::operator=(ConstructorDemo&& other)
{
	// Move assign operator
	std::cout << "Move assign operator called" << std::endl;
	if (&other == this)
	{
		return *this;
	}
	// Move operations happen here.


	return *this;
}
//a = std::move(b);