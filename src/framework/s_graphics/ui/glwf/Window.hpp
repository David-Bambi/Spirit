#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glad/glad.h>

#include <GF_E/GlfwException.hpp>
#include <GLFW_C/GLFWObject.hpp>

class Window
{
private:
  static void FrameBuffer_Size_Callback(GLFWwindow* window,
                                        int width,
                                        int height);
protected:
  GLFWwindow* _window;
public:
  Window(int height,
         int width,
         const char* title,
         bool canResizeViewPort = true);
  virtual void Draw();
  virtual void ProcessInput();
  GLFWwindow* Get();
  void Set(GLFWwindow* window);
};

#endif
