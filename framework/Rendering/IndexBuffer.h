#ifndef INDEXBUFFER_H_
#define INDEXBUFFER_H_

#include <glad/glad.h>

class IndexBuffer
{
public:
  // Constructor: initializes the VertexBuffer with a data buffer and its size.
  // Note that the buffer is bound upon construction.
  IndexBuffer(GLuint *indices, GLsizei size);
  ~IndexBuffer();

  // Bind the VertexBuffer
  void Bind() const;

  // Unbind the VertexBuffer
  void Unbind() const;

  // Fill a specific segment of the buffer specified by an offset and size with data.
  inline GLuint GetCount() const { return Count; }

private:
  GLuint IndexBufferID;
  GLuint Count;
};

#endif // VERTEXBUFFER_H_
