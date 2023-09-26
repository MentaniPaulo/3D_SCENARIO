#pragma once
#include <iostream>
#include "defines.h"


class ScreenContext{

public:
    ScreenContext(int width, int height, const char *title);
    virtual ~ScreenContext();
    int run();

private:
    GLFWwindow *window;
    int _width;
    int _height; 
    const char *_title;
};