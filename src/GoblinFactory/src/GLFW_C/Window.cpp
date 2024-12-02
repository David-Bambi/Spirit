#include <GLFW_C/Window.hpp>

// Constructor
Window::Window(int height,
               int width,
               const char* title,
               bool canResizeViewPort)
{
  this->_window = GLFW_C::CreateGlfwWindow(height, width, title);
  glViewport(0, 0, height, width);

  if(canResizeViewPort)
    glfwSetFramebufferSizeCallback(_window, Window::FrameBuffer_Size_Callback);  
}

// Setter - Getter
GLFWwindow* Window::Get()
{
  return this->_window;
}

void Window::Set(GLFWwindow* window)
{
  this->_window = window;
}

// Public method
void Window::Draw()
{
  this->ProcessInput();
  glfwSwapBuffers(this->_window);
  glfwPollEvents();       
 
}

void Window::ProcessInput()
{
  if(glfwGetKey(this->_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(this->_window, true);
}

// Static method
void Window::FrameBuffer_Size_Callback(GLFWwindow* window, int width, int height)
{
   glViewport(0, 0, width, height);
}
