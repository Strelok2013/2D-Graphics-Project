#pragma once
#include "Graphics.h"
#include "glm.hpp"
#include "Util.h"
#include "Math.h"
#include "ShaderProgram.h"


class TestingClass 
{
	 // The nuclear test site. Don't touch anything here lest ye start a nuclear fallout in the code
private:
public:
	GLuint gWorldLocation;
	TestingClass() {};
	~TestingClass() {};

	void TestFunc();
};

class ConstructorDemo
{
private:
	
public:

	ConstructorDemo();
	
	~ConstructorDemo();

	ConstructorDemo(const ConstructorDemo& other); // Copy constructor

	ConstructorDemo(ConstructorDemo&& other); // Move constructor

	ConstructorDemo& operator= (const ConstructorDemo& other); // Assignment operator

	ConstructorDemo& operator= (ConstructorDemo&& other); // Move assign operator
	
};


