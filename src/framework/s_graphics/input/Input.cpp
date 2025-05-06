#include <input/Input.hpp>

#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* Input::Window = nullptr;
float Input::xoffset = 0.0f;
float Input::yoffset = 0.0f;
float Input::xpos = 0.0f;
float Input::ypos = 0.0f;
float Input::xsboffset = 0.0f;
float Input::ysboffset = 0.0f;
bool Input::mousemov = false;
bool Input::scrollback = false;
bool Input::firstmouse = true;

bool Input::Pressed(Key key)
{
    if (Input::Window == nullptr)
        return false;

    return glfwGetKey(Input::Window, static_cast<int>(key)) == GLFW_PRESS;
}

void Input::MouseCallback(GLFWwindow* window, double xposIn, double yposIn)
{
    if (window == nullptr)
        return;

    const auto xpos = static_cast<float>(xposIn);
    const auto ypos = static_cast<float>(yposIn);

    float lastx = 0.0f;
    float lasty = 0.0f;

    if (Input::firstmouse)
    {
        lastx = xpos;
        lasty = ypos;
        Input::firstmouse = false;
    }
    else
    {
        lastx = Input::xpos;
        lasty = Input::ypos;
    }

    Input::xpos = xpos;
    Input::ypos = ypos;

    Input::xoffset = xpos - lastx;
    Input::yoffset = ypos - lasty;

    Input::mousemov = true;
}

void Input::MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (window == nullptr)
        return;
    Input::xsboffset = (float) xoffset;
    Input::ysboffset = (float) yoffset;
    Input::scrollback = true;
}