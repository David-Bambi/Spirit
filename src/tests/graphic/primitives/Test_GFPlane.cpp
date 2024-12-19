#include <iostream>

#include <GLFW_C/GLFWObject.hpp>
#include <GLFW_C/Window.hpp>
#include <GF_C/GFWindow.hpp>

#include <GF/Shape/GFPlane.hpp>
#include <GF/Sandbox/Sandbox.hpp>

int main()
{
    GLFW_C::InitializeGlfw();

    int width = 1600;
    int height = 800;

    Window* win = new Window(width,
                             height,
                             "Test Plane",
                             false /*canResizeViewPort*/);

    GFPlane* Plane = new GFPlane();

    while (!glfwWindowShouldClose(win->Get()))
    {
        win->Draw();
        Plane->Render();
    }

    return 0;
}