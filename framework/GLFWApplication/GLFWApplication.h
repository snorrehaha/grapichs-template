#ifndef GLFWAPPLICATION_H
#define GLFWAPPLICATION_H
#include <string>
#include <vector>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdlib>  // For EXIT_SUCCESS and EXIT_FAILURE


class GLFWApplication
{
public:
  GLFWApplication(const std::string& name,  const std::string& version, int width, int height); 
  ~GLFWApplication();

  // Initialization 
  virtual unsigned Init(); // Virtual function with default behavior.

  // Run function
  virtual unsigned Run(); // Pure virtual function that must be redefined.
  
  void SetKeyCallback(GLFWkeyfun callback) const;



protected:
    std::string appName;
    std::string appVersion;
    int screenWidth;
    int screenHeight;
    GLFWwindow* window; // Add this member to store the window
 
};



#endif // GLFWAPPLICATION_H
