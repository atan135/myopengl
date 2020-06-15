#include "myshader.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <glad\glad.h>

MyShader::MyShader(const char* vertexCodePath, const char* fragmentCodePath)
{
	std::ifstream vertexIO, fragmentIO;
	vertexIO.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	fragmentIO.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	std::string vertexCode, fragmentCode;
	try {
		vertexIO.open(vertexCodePath);
		fragmentIO.open(fragmentCodePath);
		std::stringstream vertexStream, fragmentStream;
		vertexStream << vertexIO.rdbuf();
		fragmentStream << fragmentIO.rdbuf();

		vertexCode = vertexStream.str();
		fragmentCode = fragmentStream.str();
	}
	catch (std::exception e)
	{
		std::cout << "Open shader file fail" << std::endl;
	}
	const char* vertexShaderSource = vertexCode.c_str();
	const char* fragmentShaderSource = fragmentCode.c_str();

	int success = 0;
	char infoLog[512];
	unsigned int vertexShader, fragmentShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, 0);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, sizeof(infoLog), 0, infoLog);
		std::cout << "Error compile vertex shader fail " << infoLog << std::endl;
	}
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, 0);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, sizeof(infoLog), 0, infoLog);
		std::cout << "Error compile fragment shader fail " << infoLog << std::endl;
	}

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, sizeof(infoLog), 0, infoLog);
		std::cout << "Error link shader fail " << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
void MyShader::Close()
{
	glDeleteProgram(ID);
}
void MyShader::Use()
{
	glUseProgram(ID);
}
void MyShader::SetBool(const char* arg, bool value)
{
	glUniform1i(glGetUniformLocation(ID, arg), (int)value);
}
void MyShader::SetInt(const char* arg, int value)
{
	glUniform1i(glGetUniformLocation(ID, arg), value);
}
void MyShader::SetFloat(const char* arg, float value)
{
	glUniform1f(glGetUniformLocation(ID, arg), value);
}
void MyShader::SetMat4(const char* arg, glm::mat4& value)
{
	glUniformMatrix4fv(glGetUniformLocation(ID, arg), 1, GL_FALSE, glm::value_ptr(value));
}
void MyShader::SetVec3(const char* arg, float v1, float v2, float v3)
{
	glUniform3f(glGetUniformLocation(ID, arg), v1, v2, v3);
}