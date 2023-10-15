
#include "defines.h"

// void __Assert(bool result){
//     if(!result){
//         std::cerr << "Assert fails" << std::endl;
//         abort();
//     }

// }

bool GLLogCall(const char* funtion, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << ")" << funtion << " " << file << ":" << line << std::endl;
        return false;
    }
    return true;
}

void GLClearError() {
    while (glGetError() != GL_NO_ERROR) {

    }
}