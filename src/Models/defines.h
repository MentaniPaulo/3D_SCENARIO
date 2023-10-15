#pragma once

#include <GL/glew.h>     // interact with OpenGL
#include <GLFW/glfw3.h>  // create windows
#include <iostream>
 
#include <cassert>
 
void GLClearError();
bool GLLogCall(const char* funtion, const char* file, int line);
 

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x,__FILE__,__LINE__))    

