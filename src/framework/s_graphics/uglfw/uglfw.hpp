#ifndef UGLFW_HPP
#define UGLFW_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace uglfw
{
  bool InitializeGlfw();
  GLFWwindow *CreateWinContext(int height,
                               int width,
                               const char *title);

  void SetViewPortResizeable(GLFWwindow *WinCtx);
}

#endif
