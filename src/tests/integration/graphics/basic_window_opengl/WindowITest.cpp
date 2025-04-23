#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <uglfw/uglfw.hpp>
#include <uglad/uglad.hpp>

void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

int main ()
{
  uglfw::InitializeGlfw();
  GLFWwindow* Win = uglfw::CreateWinContext(640, 480, "Test window");
  uglad::GladInit();

  while (!glfwWindowShouldClose(Win))
  {
    processInput(Win);
    processRender(Win);

    glfwPollEvents();
    glfwSwapBuffers(Win);
  }

  glfwTerminate();
    
return 0;
}

void processInput(GLFWwindow* win)
{
  if(glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS)
      glfwSetWindowShouldClose(win, true);
}

void processRender(GLFWwindow* win)
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT );
}