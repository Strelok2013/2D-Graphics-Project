#include "ShaderProgram.h"


void ShaderProgram::AddShader(GLuint shaderProgram, std::string fileName, GLenum shaderType)
{
	GLuint shaderObj = glCreateShader(shaderType);

	if (shaderObj == 0)
	{
		std::cout << "Error creating shader type: " << shaderType;
		exit(0);
	}

	// Some weird shenanigans involving converting the std::string into a const char*
	const GLchar* p[1];
	p[0] = fileName.c_str();
	GLint lengths[1];
	lengths[0] = strlen(fileName.c_str());

	// Get the shader source ie the text file with the code
	glShaderSource(shaderObj, 1, p, lengths);
	// Compile Shader
	glCompileShader(shaderObj);
	GLint success = 0;
	glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[1024];
		glGetShaderInfoLog(shaderObj, 1024, NULL, infoLog);
		std::cout << "Error compiling shader type: " << shaderType << std::endl;
		std::cout << infoLog << std::endl;
		loadSuccess = false;
		exit(1);
	}
	glAttachShader(shaderProgram, shaderObj);
}

void ShaderProgram::CompileShaders(std::string vertexShader, std::string fragmentShader)
{
	loadSuccess = true;
	// Generating a handle for the program (not just for shaders, but in this case, a for shader)
	programID = glCreateProgram();

	if (programID == 0)
	{
		std::cout << "Error creating shader program" << std::endl;
		exit(1);
		loadSuccess = false;
	}




	AddShader(programID, LoadFileAsString(vertexShader).c_str(), GL_VERTEX_SHADER);
	AddShader(programID, LoadFileAsString(fragmentShader).c_str(), GL_FRAGMENT_SHADER);

	GLint success = 0;
	GLchar errorLog[1024] = { 0 };

	glLinkProgram(programID);
	glGetProgramiv(programID, GL_LINK_STATUS, &success);

	if (success == 0)
	{
		glGetProgramInfoLog(programID, sizeof(errorLog), NULL, errorLog);
		std::cout << "Error linking shader program: \n" << errorLog << std::endl;
		loadSuccess = false;
		exit(1);
	}

	glValidateProgram(programID);
	glGetProgramiv(programID, GL_VALIDATE_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(programID, sizeof(errorLog), NULL, errorLog);
		std::cout << "Invalid shader program: \n" << errorLog << std::endl;
		loadSuccess = false;
		exit(1);
	}


	if (loadSuccess)
	{
		std::cout << "Shader program created successfully" << std::endl;
	}
	// In theory this shouldn't even hit, cause it'll just exit with code 1
	else
	{
		glDeleteProgram(programID);
	}


	glUseProgram(programID);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(programID);
}

void ShaderProgram::UseShader()
{

	glUseProgram(programID);
}

void ShaderProgram::SetUniform(std::string varName, int value) 
{
	GLuint varLoc = glGetUniformLocation(programID, varName.c_str());
	UseShader();
	glUniform1i(varLoc, value);
}

void ShaderProgram::SetUniform(std::string varName, float value)
{
	GLuint varLoc = glGetUniformLocation(programID, varName.c_str());
	UseShader();
	glUniform1f(varLoc, value);
}

void ShaderProgram::SetUniform(std::string varName, glm::vec2 value)
{
	GLuint varLoc = glGetUniformLocation(programID, varName.c_str());
	UseShader();
	glUniform2f(varLoc, value.x, value.y);
}

void ShaderProgram::SetUniform(std::string varName, glm::vec3 value)
{
	GLuint varLoc = glGetUniformLocation(programID, varName.c_str());
	UseShader();
	glUniform3f(varLoc, value.x, value.y, value.z);
}

void ShaderProgram::SetUniform(std::string varName, glm::mat4 value)
{
	GLuint varLoc = glGetUniformLocation(programID, varName.c_str());
	UseShader();
	glUniformMatrix4fv(varLoc, 1, GL_FALSE, &value[0][0]);
}