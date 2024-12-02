#ifndef GLFW_FUNCTIONS_HPP
#define GLFW_FUNCTIONS_HPP

#include <iostream>
#include <exception>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <GF_E/GlfwException.hpp>

namespace GLFW_C
{ 
  // Initalizing function
  void GladInit();
  void InitializeGlfw();
  
  // Creation function
  GLFWwindow* CreateGlfwWindow(int height,
                               int width,
                               const char* title,
                               GLFWmonitor* monitor = NULL,
                               GLFWwindow* share = NULL );

}

#endif
