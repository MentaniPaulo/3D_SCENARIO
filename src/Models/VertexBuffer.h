#pragma once

#include "defines.h"


class VertexBuffer{
public:
    VertexBuffer(const void *buffer, unsigned int size);
    virtual ~VertexBuffer();
    void Bind();
    void unBind();

private:
    unsigned int m_VertexBufferID;

};