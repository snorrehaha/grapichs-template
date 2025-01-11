#ifndef SHADERS_H
#define SHADERS_H
#include <string>
#include <glad/glad.h> 
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp>


class Shader
{
public:
  Shader(const std::string &vertexSrc, const std::string &fragmentSrc);
  ~Shader();

  void Bind() const;
  void Unbind() const;
  void UploadUniformInt(const std::string &name, int value);
  void UploadUniformFloat2(const std::string& name, const glm::vec2& vector);
  void UploadUniformFloat3(const std::string& name, const glm::vec3& vector);
  void UploadUniformFloat4(const std::string& name, const glm::vec4& vector);
  void UploadUniformMat4(const std::string &name, const glm::mat4 &matrix);
private:
  GLuint VertexShader;
  GLuint FragmentShader;
  GLuint ShaderProgram;

  GLuint CompileShader(GLenum shaderType, const std::string &shaderSrc);
};

#endif // SHADERS_H
