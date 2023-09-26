#pragma once

#include "defines.h"

enum ShaderKind{
    Vertex,
    Fragmented
};

class ShaderCompiler{
public:
    ShaderCompiler();
    virtual ~ShaderCompiler();

    unsigned int LoadSharder(std::string filepath, ShaderKind kind);
    unsigned int compilerShader(std::string &program, unsigned int type);
    unsigned int CreateShader();
    std::string parse(std::string filepath);
private:
};