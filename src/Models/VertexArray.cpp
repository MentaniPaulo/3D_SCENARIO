#include "VertexArray.h" 


VertexArray::VertexArray( ){ 
    GLCall(glGenVertexArrays(0,  &m_VertexArrayID));
}

VertexArray::~VertexArray(){
    GLCall(glDeleteVertexArrays(1, &m_VertexArrayID));
}

void VertexArray::Bind(){
    GLCall(glBindVertexArray(m_VertexArrayID));
}

void VertexArray::unBind(){
    GLCall(glBindVertexArray(0));
}