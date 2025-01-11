#include "VertexArray.h"
#include "VertexBuffer.h"
#include <iostream>


VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_vertexArrayID);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_vertexArrayID);
}

void VertexArray::Bind() const {
    glBindVertexArray(m_vertexArrayID);
}

void VertexArray::Unbind() const {
    glBindVertexArray(0);
}

void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
    Bind(); 
    vertexBuffer->Bind(); 
    const auto& elements = vertexBuffer->GetLayout(); 
     
    for (unsigned int i = 0; i < elements.GetAttributes().size(); i++) {
        const auto& element = elements.GetAttributes()[i]; 
        glEnableVertexAttribArray(i); 
        glVertexAttribPointer(
            i, 
            ShaderDataTypeComponentCount(element.Type), 
            ShaderDataTypeToOpenGLBaseType(element.Type), 
            element.Normalized, 
            elements.GetStride(), 
            (const void*)(uintptr_t)element.Offset 
        );
    }

    VertexBuffers.push_back(vertexBuffer);
    vertexBuffer->Unbind();
    Unbind();
}


    
void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) {
    Bind();
    this->IdxBuffer = indexBuffer;
    indexBuffer->Bind();
} 