#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include "GeometricTools.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"




class Cube
{
    public:

    std::shared_ptr<VertexArray> Init() {
        std::shared_ptr<VertexArray> va;
        auto cubeVertices = GeometricTools::UnitCubeVerticesColor;
        auto cubeIndices = GeometricTools::UnitCubeIndices;
        auto cubeBufferLayout = BufferLayout({
            {ShaderDataType::Float3, "i_Position"},
            {ShaderDataType::Float3, "i_Color"}
        });
        auto ib = std::make_shared<IndexBuffer>(cubeIndices.data(), cubeIndices.size());
        auto vb = std::make_shared<VertexBuffer>(cubeVertices.data(), cubeVertices.size() * sizeof(cubeVertices[0]));
        vb->SetLayout(cubeBufferLayout);
        va = std::make_shared<VertexArray>();
        va->AddVertexBuffer(vb);
        va->SetIndexBuffer(ib);
        return va;
    }

    
};

#endif // CUBE_H