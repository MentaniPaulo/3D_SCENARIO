#include "VertexBuffer.h"


VertexBuffer::VertexBuffer(const void *buffer, unsigned int size){
    GLCall(glGenBuffers(1, &m_VertexBufferID));//generate id and save on this variable
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID));//send which kind of id it is
    GLCall(glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW));//set all necessary data
}

VertexBuffer::~VertexBuffer(){
    GLCall(glDeleteBuffers(1, &m_VertexBufferID));
}

void VertexBuffer::Bind(){
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID));
}

void VertexBuffer::unBind(){
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}