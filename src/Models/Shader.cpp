#include "Shader.h"
#include <fstream>
#include <sstream>
#include <string>

ShaderCompiler::ShaderCompiler(std::vector<Shaders> Shaders_list){
    if( Shaders_list.size() == 0){
        std::cerr << "missing shaders" << std::endl;
        return;
    }

    for(int i = 0; i < Shaders_list.size(); i++){
        all_shaders.push_back(Shaders_list[i]);
        all_shaders[i].id = LoadSharder(all_shaders[i].filepath, all_shaders[i].kind);
    }

    m_Shader_id = CreateShader();
}
ShaderCompiler::~ShaderCompiler(){

}
unsigned int ShaderCompiler::LoadSharder(std::string filepath, ShaderKind kind){

    std::string program_file = parse(filepath);
    unsigned int id = 0;
    
    if(kind == Vertex){
        id = compilerShader(program_file, GL_VERTEX_SHADER);
    }
    if(kind == Fragmented){
        id = compilerShader(program_file, GL_VERTEX_SHADER);
    }


    return id;    
}
unsigned int ShaderCompiler::compilerShader(std::string program, unsigned int type){
    
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
    unsigned int program = glCreateProgram();

    for(int i = 0; i < all_shaders.size(); i++){
        glAttachShader(program, all_shaders[i].id);
    }

    glLinkProgram(program);
    glValidateProgram(program);

    for(int i = 0; i < all_shaders.size(); i++){
        glDeleteShader(all_shaders[i].id);
    }

    return program;
}

std::string ShaderCompiler::parse(std::string filepath){

    std::ifstream file;
    file.open(filepath);
    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}