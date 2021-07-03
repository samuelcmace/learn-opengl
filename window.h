#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window();
    Window(GLint windowWidth, GLint windowHeight);

    GLfloat getBufferWidth(){ return bufferWidth; }
    GLfloat getBufferHeight(){ return bufferHeight; }
    bool getShouldClose(){ return glfwWindowShouldClose(mainWindow); }
    void swapBuffers() { glfwSwapBuffers(mainWindow); }

    int initialize();

    ~Window();
private:
    GLFWwindow *mainWindow;
    GLint width, height;
    GLint bufferWidth, bufferHeight;
};

#endif