#pragma once

#include "defines.h"
#include <vector>

enum ShaderKind{
    Vertex,
    Fragmented
};

struct Shaders {
    ShaderKind kind;
    std::string filepath;
    unsigned int id;
};

class ShaderCompiler{
public:
    ShaderCompiler(std::vector<Shaders> Shaders_list);
    virtual ~ShaderCompiler();
    void bind();
    void unbind();

private:

    unsigned int LoadSharder(std::string filepath, ShaderKind kind);
    unsigned int compilerShader(std::string program, unsigned int type);
    unsigned int CreateShader();
    std::string parse(std::string filepath);
    std::vector<Shaders> all_shaders;

    unsigned int m_Shader_id;
};