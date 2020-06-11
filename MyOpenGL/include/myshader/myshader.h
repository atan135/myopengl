#pragma once
#include <glm\gtc\type_ptr.hpp>
class MyShader
{
public:
	int ID;
	MyShader(const char* vertexCodePath, const char* fragmentCodePath);
	void SetBool(const char* arg, bool value);
	void SetInt(const char* arg, int value);
	void SetFloat(const char* arg, float value);
	void SetMat4(const char* arg, glm::mat4& value);
	void Close();
	void Use();
};