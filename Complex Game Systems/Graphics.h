#pragma once
#define GLFW_INCLUDE_NONE
#include "glfw3.h"
#include "glad.h"

#include <iostream>

static void PrintOpenGLError()
{
	// Error checking code written by the teacher.
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{

		switch (error)
		{
		case GL_INVALID_ENUM:
			std::cout << "Invalid enum error." << std::endl;
			break;
		case GL_INVALID_VALUE:
			std::cout << "Invalid value error." << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cout << "Invalid operation error." << std::endl;
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			std::cout << "Invalid framebuffer op error." << std::endl;
			break;
		case GL_OUT_OF_MEMORY:
			std::cout << "Out of memory error." << std::endl;
			break;
		case GL_STACK_UNDERFLOW:
			std::cout << "Stack underflow error." << std::endl;
			break;
		case GL_STACK_OVERFLOW:
			std::cout << "Stack overflow error." << std::endl;
			break;
		default:
			break;
		}
	}
}