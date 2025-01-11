#include "GLFWApplication.h"

// Error callback function
void GLFWErrorCallback(int code, const char* description);
void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                GLsizei length, const GLchar* message, const void* userParam);
// Constructor
GLFWApplication::GLFWApplication(const std::string& name, const std::string& version, int width, int height) 
 : appName(name), appVersion(version), window(nullptr), screenWidth(width), screenHeight(height){}

// Destructor
GLFWApplication::~GLFWApplication() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

// Default implementation of Init()
unsigned GLFWApplication::Init() {
    
    glfwSetErrorCallback(GLFWErrorCallback);
    
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW." << std::endl;
        return EXIT_FAILURE;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Enable the debug context for OpenGL
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    window = glfwCreateWindow(screenWidth, screenHeight, appName.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD." << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glEnable(GL_DEBUG_OUTPUT); 
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(MessageCallback, nullptr);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    return EXIT_SUCCESS;
}

unsigned GLFWApplication::Run() {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "OpenGL Error: " << error << std::endl; // Log OpenGL error
        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return EXIT_SUCCESS;
}

void GLFWApplication::SetKeyCallback(GLFWkeyfun callback) const {
    glfwSetKeyCallback(window, callback);
}


void GLFWErrorCallback(int code, const char* description)
{
    std::cerr << "GLFW Error (0x" << std::hex << code << "): " << description << "\n";
}

void GLAPIENTRY MessageCallback(GLenum source,
                                GLenum type,
                                GLuint id,
                                GLenum severity,
                                GLsizei length,
                                const GLchar* message,
                                const void* userParam)
{
    std::cerr << "=== OpenGL Debug Message ===\n";
    std::cerr << "Message: " << message << "\n";
    std::cerr << "Source: ";

    switch (source) {
    case GL_DEBUG_SOURCE_API:             std::cerr << "API"; break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cerr << "Window System"; break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cerr << "Shader Compiler"; break;
    case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cerr << "Third Party"; break;
    case GL_DEBUG_SOURCE_APPLICATION:     std::cerr << "Application"; break;
    case GL_DEBUG_SOURCE_OTHER:           std::cerr << "Other"; break;
    }
    std::cerr << "\n";

    std::cerr << "Type: ";
    switch (type) {
    case GL_DEBUG_TYPE_ERROR:               std::cerr << "Error"; break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cerr << "Deprecated Behavior"; break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cerr << "Undefined Behavior"; break;
    case GL_DEBUG_TYPE_PORTABILITY:         std::cerr << "Portability"; break;
    case GL_DEBUG_TYPE_PERFORMANCE:         std::cerr << "Performance"; break;
    case GL_DEBUG_TYPE_MARKER:              std::cerr << "Marker"; break;
    case GL_DEBUG_TYPE_PUSH_GROUP:          std::cerr << "Push Group"; break;
    case GL_DEBUG_TYPE_POP_GROUP:           std::cerr << "Pop Group"; break;
    case GL_DEBUG_TYPE_OTHER:               std::cerr << "Other"; break;
    }
    std::cerr << "\n";

    std::cerr << "Severity: ";
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH:         std::cerr << "High"; break;
    case GL_DEBUG_SEVERITY_MEDIUM:       std::cerr << "Medium"; break;
    case GL_DEBUG_SEVERITY_LOW:          std::cerr << "Low"; break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: std::cerr << "Notification"; break;
    }
    std::cerr << "\n";

    std::cerr << "ID: " << id << "\n";
    std::cerr << "=============================\n";
}


