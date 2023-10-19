#include "IndexBuffer.h" 


IndexBuffer::IndexBuffer(const void *buffer, unsigned int counter){

    ASSERT(sizeof(unsigned int) == sizeof(GLuint));//

    GLCall(glGenBuffers(1, &m_IndexBufferID));//generate id and save on this variable
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID));//send which kind of id it is
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, counter * sizeof(GLuint) , buffer, GL_STATIC_DRAW));//load data
}

IndexBuffer::~IndexBuffer(){
    GLCall(glDeleteBuffers(1, &m_IndexBufferID));
}

void IndexBuffer::Bind(){
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID));
}

void IndexBuffer::unBind(){
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}