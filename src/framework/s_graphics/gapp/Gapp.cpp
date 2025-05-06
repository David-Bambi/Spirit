#include <gapp/Gapp.hpp>

#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>

void Gapp::Init()
{
    uglfw::InitializeGlfw();
    _window =
        uglfw::CreateWinContext(_setting.SCREEN_WIDTH, _setting.SCREEN_HEIGHT, _setting.APP_NAME);
    uglad::GladInit();
}

void Gapp::Run()
{
    while (!glfwWindowShouldClose(_window))
    {
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(_window, true);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(_window);
    }
}

void Gapp::Shutdown()
{
    glfwTerminate();
}
