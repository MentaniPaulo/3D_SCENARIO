#pragma once
#include "defines.h"

class VertexArray{
public:
    VertexArray( );
    virtual ~VertexArray();
    void Bind();
    void unBind();

private:
    unsigned int m_VertexArrayID;
};


