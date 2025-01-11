#include "Shaders.h"
#include <iostream>

Shader::Shader(const std::string &vertexSrc, const std::string &fragmentSrc)
{
    VertexShader = CompileShader(GL_VERTEX_SHADER, vertexSrc);    
    FragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);
    
    ShaderProgram = glCreateProgram();
    glAttachShader(ShaderProgram, VertexShader);
    glAttachShader(ShaderProgram, FragmentShader);
    glLinkProgram(ShaderProgram);

    // Check linking status
    GLint success;
    glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(ShaderProgram, 512, nullptr, infoLog);
        std::cerr << "Shader Program Linking Failed: " << infoLog << std::endl;
    }

    // Shader objects can be deleted once they have been linked into the program
    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);
}


Shader::~Shader()
{
    glDeleteProgram(ShaderProgram);
}

void Shader::Bind() const
{
    glUseProgram(ShaderProgram);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

void Shader::UploadUniformInt(const std::string &name, int value)
{
    GLuint location = glGetUniformLocation(ShaderProgram, name.c_str());
    if (location != -1)
    {
        glUniform1i(location, value);
    }
    else
    {
        std::cerr << "Uniform " << name << " not found in shader" << std::endl;
    }
}

void Shader::UploadUniformFloat2(const std::string &name, const glm::vec2 &vector)
{
    GLuint location = glGetUniformLocation(ShaderProgram, name.c_str());
    if (location != -1)
    {
        glUniform2f(location, vector.x, vector.y);
    }
    else
    {
        std::cerr << "Uniform " << name << " not found in shader" << std::endl;
    }
}

void Shader::UploadUniformFloat3(const std::string &name, const glm::vec3 &vector)
{
    GLuint location = glGetUniformLocation(ShaderProgram, name.c_str());
    if (location != -1)
    {
        glUniform3f(location, vector.x, vector.y, vector.z);
    }
    else
    {
        std::cerr << "Uniform " << name << " not found in shader" << std::endl;
    }
}

void Shader::UploadUniformFloat4(const std::string &name, const glm::vec4 &vector)
{
    GLuint location = glGetUniformLocation(ShaderProgram, name.c_str());
    if (location != -1)
    {
        glUniform4f(location, vector.x, vector.y, vector.z, vector.w);
    }
    else
    {
        std::cerr << "Uniform " << name << " not found in shader" << std::endl;
    }
}

void Shader::UploadUniformMat4(const std::string &name, const glm::mat4 &matrix)
{
    GLint location = glGetUniformLocation(ShaderProgram, name.c_str());

    if (location != -1)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
    }
    else
    {
        std::cerr << "Uniform " << name << " not found in shader" << std::endl;
    }
}


GLuint Shader::CompileShader(GLenum shaderType, const std::string &shaderSrc)
{
    GLuint shader = glCreateShader(shaderType);
    const GLchar *ss = shaderSrc.c_str();
    glShaderSource(shader, 1, &ss, nullptr);
    glCompileShader(shader);

    // Check compilation status
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Shader Compilation Failed: " << infoLog << std::endl;
    }

    return shader;
}
