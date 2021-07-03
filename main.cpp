#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "window.h"
#include "mesh.h"
#include "shader.h"

Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader*> shaderList;

static const char* vShader = "../shaders/shader.vert";
static const char* fShader = "../shaders/shader.frag";

void CreateObjects()
{
  unsigned int indices[] = {
    0, 3, 1,
    1, 3, 2,
    2, 3, 0,
    0, 1, 2
  };

  GLfloat vertices[] = {
    -1.0f, -1.0f, 0.0f,
     0.0f, -1.0f, 1.0f,
     1.0f, -1.0f, 0.0f,
     0.0f,  1.0f, 0.0f
  };

  Mesh *object = new Mesh();
  object->CreateMesh(vertices, indices, 12, 12);
  meshList.push_back(object);

  Mesh *objectTwo = new Mesh();
  objectTwo->CreateMesh(vertices, indices, 12, 12);
  meshList.push_back(objectTwo);
}

void CreateShaders()
{
  Shader *shaderOne = new Shader();
  shaderOne->CreateFromFiles(vShader, fShader);
  shaderList.push_back(shaderOne);
}

int main()
{
  mainWindow = Window(800, 600);
  mainWindow.initialize();

  CreateObjects();
  CreateShaders();

  GLuint uniformProjection = 0, uniformModel = 0;

  glm::mat4 projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth()/(GLfloat)mainWindow.getBufferHeight(), 0.1f, 100.0f);

  while(!mainWindow.getShouldClose())
  {
    glfwPollEvents();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderList[0]->UseShader(); 
    uniformModel = shaderList[0]->GetModelLocation();
    uniformProjection = shaderList[0]->GetProjectionLocation();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
    model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
    meshList[0]->RenderMesh();

    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 1.0f, -2.5f));
    model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
    meshList[1]->RenderMesh();

    glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

    glUseProgram(0);

    mainWindow.swapBuffers();
  }

  return 0;
}
