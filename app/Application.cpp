#include "Application.h"
#include "RenderCommands.h"
#include "GeometricTools.h"
#include "Shaders.h"
#include "PerspectiveCamera.h"
#include <iostream>
#include "TextureManager.h"
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


// if using textures
// #ifndef TEXTURES_PATH
// #define TEXTURES_PATH 
// #endif

// Callback function for key presses
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

// Constructor and Destructor
Application::Application(const std::string& name, const std::string& version)
    : GLFWApplication(name, version, 1280, 720){}
Application::~Application(){}


// Run the application
unsigned Application::Run()
{
   std::cout << "Running " << appName << " Version: " << appVersion<<  std::endl;
    SetKeyCallback(keyCallback);
    RenderLoop();
    return 0;
}

// The render loop
void Application::RenderLoop()
{
    std::cout << "Rendering..." << std::endl;


    glm::vec4 clearColor = glm::vec4(0.5f, 0.5f, 0.5f, 1.0f);
    RenderCommands::SetClearColor(clearColor);

    while (!glfwWindowShouldClose(window)) {
        // Clear the screen with a default color (e.g., black)
        RenderCommands::Clear();
        
        // Testing 
        
        glfwSwapBuffers(window);
        // Poll and handle input events
        glfwPollEvents();
    }

    // Optional: Unbind resources if necessary before exiting
    std::cout << "Exiting rendering loop..." << std::endl;
}

// Function to register key presses
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (key) {
        case GLFW_KEY_Q:
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        }
    }
}


