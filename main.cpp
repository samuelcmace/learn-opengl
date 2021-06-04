#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

const GLint WIDTH = 800, HEIGHT = 600;

int main()
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

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", NULL, NULL);
    if(!mainWindow)
    {
      printf("GLFW window creation failed!\n");
      glfwTerminate();
      return 1;
    }

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    glfwMakeContextCurrent(mainWindow);

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK)
    {
      printf("GLEW initalization failed!\n");
      glfwDestroyWindow(mainWindow);
      glfwTerminate();
      return 1;
    }

    glViewport(0, 0, bufferWidth, bufferHeight);

    while(!glfwWindowShouldClose(mainWindow))
    {
      glfwPollEvents();

      glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      glfwSwapBuffers(mainWindow);
    }

    return 0;
}
