add_library(Rendering VertexBuffer.cpp IndexBuffer.cpp VertexArray.cpp OrthographicCamera.cpp PerspectiveCamera.cpp Camera.cpp)
add_library(Framework::Rendering ALIAS Rendering)
target_include_directories(Rendering PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Rendering PUBLIC glad glfw glm)


