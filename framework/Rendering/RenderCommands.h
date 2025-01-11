#ifndef RENDERCOMMANDS_H
#define RENDERCOMMANDS_H

#include <glad/glad.h>
#include <memory>
#include "VertexArray.h"
#include <glm/glm.hpp>

namespace RenderCommands {
  inline void Clear(GLuint mode = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) {
    glClear(mode);
  }

  inline void SetPolygonMode(GLuint face, GLuint mode) {
    glPolygonMode(face, mode);
  }

  inline void DrawIndex(const std::shared_ptr<VertexArray>& vao, GLenum primitive){
    glDrawElements(primitive, vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
    // Check for OpenGL errors
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL Error: " << error << std::endl;
    }
  }

  inline void SetClearColor(glm::vec4 &color) {
    glClearColor(color[0], color[1], color[2], color[3]);
  }

  inline void SetWireframeMode() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  }

  inline void SetSolidMode() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  }

  inline void SetBlend() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  }

  inline void SetDepthTest() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
  }
  inline void DisableDepthTest() {
    glDisable(GL_DEPTH_TEST);
  }
}


#endif // RENDERCOMMANDS_H