#ifndef UGLFW_HPP
#define UGLFW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <exception>
#include <iostream>
#include <vector>

namespace uglfw
{
bool InitializeGlfw();
GLFWwindow* CreateWinContext(int height, int width, const char* title);

void SetViewPortResizeable(GLFWwindow* WinCtx);
} // namespace uglfw

#endif
