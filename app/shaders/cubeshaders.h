#ifndef CUBESHADERS_H
#define CUBESHADERS_H
#include <string>

// Vertex Shader
static const std::string cubeVertexShaderSrc = R"(
#version 430 core

layout(location = 0) in vec3 i_Position; // Vertex position
layout(location = 1) in vec3 i_Color;    // Vertex color

uniform mat4 u_model = mat4(1.0);       // Model matrix
uniform mat4 u_view = mat4(1.0);        // View matrix
uniform mat4 u_projection = mat4(1.0);  // Projection matrix

out vec3 vs_Color; // Output color

void main()
{
    gl_Position = u_projection * u_view * u_model * vec4(i_Position, 1.0); // Apply transformation to the position
    vs_Color = i_Color; // Pass the color to the fragment shader
}
)";

// Fragment Shader
static const std::string cubeFragmentShaderSrc = R"(
#version 430 core

in vec3 vs_Color; // Input color
out vec4 FragColor; // Final output color

void main()
{
    FragColor = vec4(vs_Color, 1.0); // Default white color
}
)";

#endif // CUBESHADERS_H
