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
    bool* getKeys() { return keys; }
    void swapBuffers() { glfwSwapBuffers(mainWindow); }

    GLfloat getXChange();
    GLfloat getYChange();

    int initialize();

    ~Window();
private:
    GLFWwindow *mainWindow;
    GLint width, height;
    GLint bufferWidth, bufferHeight;

    bool keys[1024];

    GLfloat lastX;
    GLfloat lastY;
    GLfloat xChange;
    GLfloat yChange;
    bool mouseFirstMoved;

    void createCallBacks();
    static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
    static void handleMouse(GLFWwindow* window, double xPos, double yPos);
};

#endif