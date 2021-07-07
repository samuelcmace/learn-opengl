#include "window.h"

Window::Window()
{
    width = 800;
    height = 600;

    xChange = 0.0f;
    yChange = 0.0f;

    for(size_t i = 0; i < 1024; i++)
    {
        keys[i] = 0;
    }
}

Window::Window(GLint windowWidth, GLint windowHeight)
{
    width = windowWidth;
    height = windowHeight;

    for(size_t i = 0; i < 1024; i++)
    {
        keys[i] = 0;
    }
}

int Window::initialize()
{
    if(!glfwInit())
    {
        printf("GLFW Intialization Failed!");
        glfwTerminate();
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    mainWindow = glfwCreateWindow(width, height, "Learn OpenGL", NULL, NULL);
    if(!mainWindow)
    {
      printf("GLFW window creation failed!\n");
      glfwTerminate();
      return 1;
    }

    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    glfwMakeContextCurrent(mainWindow);

    createCallBacks();
    glfwSetInputMode(mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK)
    {
      printf("GLEW initalization failed!\n");
      glfwDestroyWindow(mainWindow);
      glfwTerminate();
      return 1;
    }

    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, bufferWidth, bufferHeight);

    glfwSetWindowUserPointer(mainWindow, this);
}

void Window::createCallBacks()
{
    glfwSetKeyCallback(mainWindow, handleKeys);
    glfwSetCursorPosCallback(mainWindow, handleMouse);
}

GLfloat Window::getXChange()
{
    GLfloat theChange = xChange;
    xChange = 0;
    return theChange;
}

GLfloat Window::getYChange()
{
    GLfloat theChange = yChange;
    yChange = 0;
    return theChange;
}

void Window::handleKeys(GLFWwindow* window, int key, int code, int action, int mode)
{
    Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if(key >= 0 && key < 1024)
    {
        if(action == GLFW_PRESS)
        {
            theWindow->keys[key] = true;
        }
        else if(action == GLFW_RELEASE)
        {
            theWindow->keys[key] = false;
        }
    }
}

void Window::handleMouse(GLFWwindow* window, double xPos, double yPos)
{
    Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

    if(theWindow ->mouseFirstMoved)
    {
        theWindow->lastX = xPos;
        theWindow->lastY = yPos;
        theWindow->mouseFirstMoved = false;
    }

    theWindow->xChange = xPos - theWindow->lastX;
    theWindow->yChange = theWindow->lastY - yPos;

    theWindow->lastX = xPos;
    theWindow->lastY = yPos;
}

Window::~Window()
{
    glfwDestroyWindow(mainWindow);
    glfwTerminate();
}