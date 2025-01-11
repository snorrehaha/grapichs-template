#ifndef APPLICATION_H
#define APPLICATION_H

#include "GLFWApplication.h"
#include "Shaders.h"
#include "VertexArray.h"
#include "Camera.h"
#include "PerspectiveCamera.h"

class Application : public GLFWApplication
{
public:
    Application(const std::string& name, const std::string& version);
    virtual ~Application();

    // Override the Run function
    virtual unsigned Run()  override; 

private:
    void RenderLoop();
};

#endif // APPLICATION_H
