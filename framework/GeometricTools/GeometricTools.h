#ifndef GEOMETRICTOOLS_H
#define GEOMETRICTOOLS_H
#include <array>
#include <vector>


namespace GeometricTools {
  constexpr std::array<float, 3*2> UnitTriangle2D = {-0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f}; // [2,3]
}

namespace GeometricTools {
  constexpr std::array<float, 4*2> UnitSquare2D = {-0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f}; // [3,3]
}

namespace GeometricTools {
  template<unsigned int X, unsigned int Y>
constexpr std::array<float, (X + 1) * (Y + 1) * 4> UnitGridGeometry2DWTCoords() {
    std::array<float, (X + 1) * (Y + 1) * 4> vertices = {};
    unsigned int index = 0;

    for (unsigned int j = 0; j <= Y; ++j) {
        for (unsigned int i = 0; i <= X; ++i) {
            // Position (mapped to [-0.5, 0.5] for each axis)
            vertices[index++] = -0.5f + (static_cast<float>(i) / X); // x-coordinate
            vertices[index++] = -0.5f + (static_cast<float>(j) / Y); // y-coordinate

            // Texture coordinates (mapped to [0, 1] for each axis)
            vertices[index++] = static_cast<float>(i) / X; // u-coordinate
            vertices[index++] = static_cast<float>(j) / Y; // v-coordinate
        }
    }

    return vertices;
}




  std::vector<float> UnitGridGeometry2DWTCoords(unsigned int X, unsigned int Y)
  {
      std::vector<float> vertices;
      vertices.reserve((X + 1) * (Y + 1) * 4);

      for (unsigned int i = 0; i <= X; ++i) {
          for (unsigned int j = 0; j <= Y; ++j) {
              // Position
              vertices.push_back(-1.0f + 1.0f * i / X); // x-position
              vertices.push_back(-1.0f + 1.0f * j / Y); // y-position

              // Texture coordinates
              vertices.push_back(static_cast<float>(i) / X); // u-texture coordinate
              vertices.push_back(static_cast<float>(j) / Y); // v-texture coordinate
          }
      }

      return vertices;
  }

}




namespace GeometricTools {
  
  // Function to generate vertices for a grid with DivX and DivY divisions
  template <int DivX, int DivY>
  std::vector<float> UnitGridGeometry2D() {
    std::vector<float> vertices;
    float stepX = 1.0f / DivX; // Step size for X
    float stepY = 1.0f / DivY; // Step size for Y

    for (int y = 0; y <= DivY; ++y) {
      for (int x = 0; x <= DivX; ++x) {
        vertices.push_back(x * stepX - 0.5f); // X position
        vertices.push_back(y * stepY - 0.5f); // Y position
      }
    }
    return vertices;
  }

  // Function to generate topology indices for triangles in the grid
  template <int DivX, int DivY>
  std::vector<unsigned int> UnitGridTopologyTriangles() {
    std::vector<unsigned int> indices;

    for (int y = 0; y < DivY; ++y) {
      for (int x = 0; x < DivX; ++x) {
        int topLeft = y * (DivX + 1) + x;
        int topRight = topLeft + 1;
        int bottomLeft = (y + 1) * (DivX + 1) + x;
        int bottomRight = bottomLeft + 1;

        // First triangle
        indices.push_back(topLeft);
        indices.push_back(bottomLeft);
        indices.push_back(topRight);

        // Second triangle
        indices.push_back(topRight);
        indices.push_back(bottomLeft);
        indices.push_back(bottomRight);
      }
    }
    return indices;
  }
}





namespace GeometricTools {

  constexpr std::array<float, 24 * 5> UnitCubeVertices = 
  {
      // Position (x, y, z)   // Texture coordinates (u, v)
      // Front face
      -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,
       0.5f, -0.5f,  0.5f,    1.0f, 0.0f,
       0.5f,  0.5f,  0.5f,    1.0f, 1.0f,
      -0.5f,  0.5f,  0.5f,    0.0f, 1.0f,

      // Back face
      -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,
       0.5f, -0.5f, -0.5f,    1.0f, 0.0f,
       0.5f,  0.5f, -0.5f,    1.0f, 1.0f,
      -0.5f,  0.5f, -0.5f,    0.0f, 1.0f,

      // Right face
       0.5f, -0.5f, -0.5f,    0.0f, 0.0f,
       0.5f,  0.5f, -0.5f,    1.0f, 0.0f,
       0.5f,  0.5f,  0.5f,    1.0f, 1.0f,
       0.5f, -0.5f,  0.5f,    0.0f, 1.0f,

      // Left face
      -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,
      -0.5f,  0.5f, -0.5f,    1.0f, 0.0f,
      -0.5f,  0.5f,  0.5f,    1.0f, 1.0f,
      -0.5f, -0.5f,  0.5f,    0.0f, 1.0f,

      // Top face
      -0.5f,  0.5f, -0.5f,    0.0f, 0.0f,
       0.5f,  0.5f, -0.5f,    1.0f, 0.0f,
       0.5f,  0.5f,  0.5f,    1.0f, 1.0f,
      -0.5f,  0.5f,  0.5f,    0.0f, 1.0f,

      // Bottom face
      -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,
       0.5f, -0.5f, -0.5f,    1.0f, 0.0f,
       0.5f, -0.5f,  0.5f,    1.0f, 1.0f,
      -0.5f, -0.5f,  0.5f,    0.0f, 1.0f
  };

  constexpr std::array<unsigned int, 36> UnitCubeIndices = 
  {
      // Front face
      0, 1, 2,  // First triangle
      2, 3, 0,  // Second triangle

      // Back face
      4, 5, 6,  // First triangle
      6, 7, 4,  // Second triangle

      // Right face
      8, 9, 10, // First triangle
      10, 11, 8, // Second triangle

      // Left face
      12, 13, 14, // First triangle
      14, 15, 12, // Second triangle

      // Top face
      16, 17, 18, // First triangle
      18, 19, 16, // Second triangle

      // Bottom face
      20, 21, 22, // First triangle
      22, 23, 20  // Second triangle
  };
  constexpr std::array<float, 24 * 6> UnitCubeVerticesColor = 
  {
      // Position (x, y, z)   // color (r, g, b)
      // Front face
      -0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
       0.5f, -0.5f,  0.5f,    0.0f, 1.0f, 0.0f,
       0.5f,  0.5f,  0.5f,    0.0f, 1.0f,0.0f,
      -0.5f,  0.5f,  0.5f,    0.0f, 1.0f,0.0f,

      // Back face
      -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,1.0f,
       0.5f, -0.5f, -0.5f,    0.0f, 0.0f,1.0f,
       0.5f,  0.5f, -0.5f,    0.0f, 0.0f,1.0f,
      -0.5f,  0.5f, -0.5f,    0.0f, 0.0f,1.0f,

      // Right face
       0.5f, -0.5f, -0.5f,    1.0f, 0.0f,0.0f,
       0.5f,  0.5f, -0.5f,    1.0f, 0.0f,0.0f,
       0.5f,  0.5f,  0.5f,    1.0f, 0.0f,0.0f,
       0.5f, -0.5f,  0.5f,    1.0f, 0.0f,0.0f,

      // Left face
      -0.5f, -0.5f, -0.5f,    1.0f, 0.5f,0.0f,
      -0.5f,  0.5f, -0.5f,    1.0f, 0.5f,0.0f,
      -0.5f,  0.5f,  0.5f,    1.0f, 0.5f,0.0f,
      -0.5f, -0.5f,  0.5f,    1.0f, 0.5f,0.0f,

      // Top face
      -0.5f,  0.5f, -0.5f,    1.0f, 1.0f,1.0f,
       0.5f,  0.5f, -0.5f,    1.0f, 1.0f,1.0f,
       0.5f,  0.5f,  0.5f,    1.0f, 1.0f,1.0f,
      -0.5f,  0.5f,  0.5f,    1.0f, 1.0f,1.0f,

      // Bottom face
      -0.5f, -0.5f, -0.5f,    1.0f, 1.0f,0.0f,
       0.5f, -0.5f, -0.5f,    1.0f, 1.0f,0.0f,
       0.5f, -0.5f,  0.5f,    1.0f, 1.0f,0.0f,
      -0.5f, -0.5f,  0.5f,    1.0f, 1.0f,0.0f,
  };

}


#endif // GEOMETRIC_TOOLS_H