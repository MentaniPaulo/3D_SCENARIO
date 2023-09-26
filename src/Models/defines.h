#pragma once

#include <GL/glew.h>     // interact with OpenGL
#include <GLFW/glfw3.h>  // create windows
#include <iostream>

// #define NDEBUG
#include <cassert>

//inline void __Assert(bool result){ if(!result)abort();};
void GLLogCall(const char* funtion, const char* file, int line);
void GLClearError();

//#define ASSERT(x) if (!(x)) __debugbreak();

//#define ASSERT(x) __Assert(x);
//#define ASSERT(x) if(!(x)){ ; } //check why on vscode it do not work
//#define ASSERT(x) ;


#define GLCall(x) GLClearError();\
    x;\
    GLLogCall(#x,__FILE__,__LINE__);\
    //ASSERT(GLLogCall(#x,__FILE__,__LINE__))
    //check if there is error and print out the line and function
