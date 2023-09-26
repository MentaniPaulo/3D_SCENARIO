
#include "defines.h"

// void __Assert(bool result){
//     if(!result){
//         std::cerr << "Assert fails" << std::endl;
//         abort();
//     }

// }

void GLLogCall(const char* function, const char* file, int line){

    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << ")" << function << " " << file << ":" << line << std::endl;
        abort();
    }
    
}

void GLClearError() {
    while (glGetError() != GL_NO_ERROR) {

    }
}