#include "Shader.h"
#include <fstream>
#include <sstream>
#include <string>

ShaderCompiler::ShaderCompiler(){

}
ShaderCompiler::~ShaderCompiler(){

}
unsigned int ShaderCompiler::LoadSharder(std::string filepath, ShaderKind kind){

    std::string program_file = parse(filepath);
    const char* program_file_str = program_file.c_str();
    if(kind == Vertex){
        //unsigned int vs = CompileShader(GL_VERTEX_SHADER, program_file_str);
    }
    return 0;    
}
unsigned int ShaderCompiler::compilerShader(std::string &program, unsigned int type){
    
    unsigned int id = 0;
    const char *src = program.c_str();

    GLCall(id = glCreateShader(type));
    GLCall(glShaderSource(id, 1, &src, nullptr));

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if(result == GL_FALSE){
        int size;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &size);
        char* message = new char[size];
        glGetShaderInfoLog(id, size, &size, &message[0]);
        std::cerr << "Fail to compile shader" << std::endl;
        std::cerr << message << std::endl;
    }

    return id; 
}

unsigned int ShaderCompiler::CreateShader(){

    return 0;
}

std::string ShaderCompiler::parse(std::string filepath){

    std::ifstream file;
    file.open(filepath);
    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}