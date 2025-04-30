#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <input/Input.hpp>
#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>

int main() {
  uglfw::InitializeGlfw();
  GLFWwindow *Win = uglfw::CreateWinContext(800, 600, "GF");
  uglad::GladInit();
  Input::Window = Win;
  return 0;
}
