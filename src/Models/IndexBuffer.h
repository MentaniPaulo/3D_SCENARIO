#pragma once
#include "defines.h"

class IndexBuffer{
public:
    IndexBuffer(const void *buffer, unsigned int counter);
    virtual ~IndexBuffer();
    void Bind();
    void unBind();

private:
    unsigned int m_IndexBufferID;
};