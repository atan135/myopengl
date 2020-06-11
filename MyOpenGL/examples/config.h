#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include "../include/myshader/myshader.h"
// ͨ������
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);
void init_glfw();
GLFWwindow* create_glfwwindow(const char* title, int width = WINDOW_WIDTH, int height = WINDOW_HEIGHT);
int init_glad(); 

// ���Դ���
int testwindow();
int testshader();