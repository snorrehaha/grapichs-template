add_library(Shaders Shaders.cpp)
add_library(Framework::Shaders ALIAS Shaders)
target_include_directories(Shaders PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Shaders PUBLIC glm glad) 