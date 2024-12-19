#include <GLFW_C/GLFWObject.hpp>

void GLFW_C::InitializeGlfw()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);  
}

GLFWwindow* GLFW_C::CreateGlfwWindow(int height,
                                     int width,
                                     const char* title,
                                     GLFWmonitor* monitor,
                                     GLFWwindow * share)
{
  GLFWwindow* window = glfwCreateWindow(height,
                                        width,
                                        title,
                                        monitor,
                                        share);
  if (window == NULL)
    {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return NULL;
    }

  glfwMakeContextCurrent( window );
  GLFW_C::GladInit();
  
  return window;
}

void GLFW_C::GladInit()
{
  try
    {
      if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
          throw FailedInitGladException();
        }
    }
  catch(FailedInitGladException& E)
    {
      std::cout << E.what() << std::endl;
    }
}


