#ifndef INPUT_HPP
#define INPUT_HPP

#include <GLFW/glfw3.h>
#include <input/Key.hpp>

class Input
{
  public:
    static bool Pressed(Key key);
    static GLFWwindow* Window;
    static void MouseCallback(GLFWwindow* window, double xposIn, double yposIn);
    static void MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

    static float xpos;
    static float ypos;
    static float xoffset;
    static float yoffset;
    static bool mousemov;
    static bool firstmouse;
    static float xsboffset;
    static float ysboffset;
    static bool scrollback;
};

#endif