#include "IndexBuffer.h"
#include "ShadersDataTypes.h"

IndexBuffer::IndexBuffer(GLuint *indices, GLsizei count)
: Count(count){  // Maybe this : Count(size / ShaderDataTypeSize(ShaderDataType::Int))
    glGenBuffers(1, &IndexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);  
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLsizei), indices, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer(){
    glDeleteBuffers(1, &IndexBufferID);
}

void IndexBuffer::Bind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBufferID);

}

void IndexBuffer::Unbind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


