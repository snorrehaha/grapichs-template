add_library(Texture TextureManager.cpp)
add_library(Framework::Texture ALIAS Texture)
target_include_directories(Texture PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Texture PUBLIC stb glad)


