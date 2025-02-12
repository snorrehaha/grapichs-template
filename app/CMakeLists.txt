project(app)
add_executable(${PROJECT_NAME} main.cpp Application.cpp)

# Link the Framework library and external dependencies
target_link_libraries(${PROJECT_NAME} PRIVATE Framework::GLFWApplication glfw glad)
target_link_libraries(${PROJECT_NAME} PRIVATE Framework::GeometricTools)
target_link_libraries(${PROJECT_NAME} PRIVATE Framework::Rendering)
target_link_libraries(${PROJECT_NAME} PRIVATE Framework::Shaders)
target_link_libraries(${PROJECT_NAME} PRIVATE Framework::Texture)

target_compile_definitions(${PROJECT_NAME} PRIVATE TEXTURES_DIR="${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/textures/")
target_compile_definitions(${PROJECT_NAME} PRIVATE STB_IMAGE_IMPLEMENTATION)
target_compile_definitions(${PROJECT_NAME} PRIVATE STB_IMAGE_STATIC)


#[===[
add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/resources/textures/cube_texture.png
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/textures/cube_texture.png
)

add_custom_command(
  TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/resources/textures/floor_texture.png
  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/textures/floor_texture.png
)
]===]
