#include "ScreenContext.h"
#include "Teste.h"

ScreenContext::ScreenContext(int width, int height, const char *title):
    window(nullptr),
    _width(width),
    _height(height), 
    _title(title)
{
    
}

ScreenContext::~ScreenContext(){
    
}

int ScreenContext::run(){

    if (glfwInit() == 0) {
        std::cerr << "GLFW failed to initiate." << std::endl;
        return -1;
    }

    window = glfwCreateWindow(_width, _height, _title, nullptr, nullptr);

    if (window == nullptr) {
        std::cerr << "GLFW failed to create window." << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);
  
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLFW failed to create window." << std::endl;
        glfwTerminate();
        return -1;
    }

    Test_initial::initial_configuration();

    while (glfwWindowShouldClose(window) == 0) {
        // clear the window
        glClear(GL_COLOR_BUFFER_BIT);

        Test_initial::loop_render();

        // swap buffer
        glfwSwapBuffers(window);

        // process user events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}