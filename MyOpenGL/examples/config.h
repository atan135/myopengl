﻿#pragma once
#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include "../include/stb-master/stb_image.h"
#include <iostream>
#include "../include/myshader/myshader.h"
#include "camera.h"
// 通用配置
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void process_input(GLFWwindow* window);
void init_glfw();
GLFWwindow* create_glfwwindow(const char* title, int width = WINDOW_WIDTH, int height = WINDOW_HEIGHT);
int init_glad(); 

// 测试代码
int testwindow();
int testshader();
int testimage();
int testgml();
int testspace();
int testcamera();
// 光照测试
int testlightbase();
int testphonelight();