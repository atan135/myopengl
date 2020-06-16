#pragma once
#include <glm\gtc\type_ptr.hpp>
class MyShader
{
public:
	int ID;
	MyShader(const char* vertexCodePath, const char* fragmentCodePath);
	void setBool(const char* arg, bool value);
	void setInt(const char* arg, int value);
	void setFloat(const char* arg, float value);
	void setMat4(const char* arg, glm::mat4& value);
	void setVec3(const char* arg, float v1, float v2, float v3);
	void setVec3(const char* arg, glm::vec3& val);
	void Close();
	void use();
};