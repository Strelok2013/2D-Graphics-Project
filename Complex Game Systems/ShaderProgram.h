#pragma once
#include "Graphics.h"
#include "Util.h"
#include "Math.h"

class ShaderProgram
{

private:
	GLuint programID;

	bool loadSuccess = false;

public:
	ShaderProgram() {};
	~ShaderProgram();

	void AddShader(GLuint shaderProgram, std::string fileName, GLenum shaderType); // Used in CompileShaders();
	void CompileShaders(std::string vertexShader, std::string fragmentShader); // Compiles a shader from two files (.fsd and .vsd file (take care to ensure both files match, else you will get compile errors))

	void UseShader(); // Sets the currently active shader

	void SetUniform(std::string varName, int value); // Sets the uniforms of a given shader program, varName must match the name of the uniform inside the shader (.fsd and .vsd files)
	void SetUniform(std::string varName, float value);
	void SetUniform(std::string varName, glm::vec2 value);
	void SetUniform(std::string varName, glm::vec3 value);
	void SetUniform(std::string varName, glm::mat4 value);


};
