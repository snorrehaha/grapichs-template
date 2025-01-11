#ifndef __TRIANGLE_H_
#define __TRIANGLE_H_

#include <string>

static const std::string triangleVertexShaderSrc = R"(

#version 430 core

layout(location = 0) in vec2 square_position;

out vec4 vertexColor;

void main()
{
    gl_Position = vec4(square_position, 0.0f, 1.0f);  // Set the position in 4D

    // Calculate the checkerboard color based on position
    float checkerSize = 1.0 / 8.0; // Assuming an 8x8 grid
    int xIndex = int((square_position.x + 0.5) / checkerSize);
    int yIndex = int((square_position.y + 0.5) / checkerSize);
    
    // Alternate colors based on the sum of indices
    if ((xIndex + yIndex) % 2 == 0) {
        vertexColor = vec4(0.0f, 0.0f, 0.0f, 1.0f); // Black
    } else {
        vertexColor = vec4(1.0f, 1.0f, 1.0f, 1.0f); // White
    }
})";


static const std::string triangleFragmentShaderSrc = R"(

#version 430 core

in vec4 v_Color;
out vec4 color;

void main()
{
color = v_Color;
}

)";

#endif // __TRIANGLE_H_
