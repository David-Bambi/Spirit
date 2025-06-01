#include <gapp/Gapp.hpp>

#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>
#include <input/Input.hpp>
#include <time/Time.hpp>

Gapp* Gapp::CurrentGapp = nullptr;

void Gapp::Run()
{
    CurrentGapp = this;
    InitContext();
    BeforeRenderPhase();
    RenderPhase();
    CleanUp();
}

void Gapp::InitContext()
{
    uglfw::InitializeGlfw();
    _window =
        uglfw::CreateWinContext(_setting.SCREEN_WIDTH, _setting.SCREEN_HEIGHT, _setting.APP_NAME);
    uglad::GladInit();

    if (_setting.ENABLE_DEPTH_TEST)
        glEnable(GL_DEPTH_TEST);

    if (_setting.ENABLE_CURSOR)
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    else
        glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    Input::Window = _window;
    glfwSetCursorPosCallback(_window, Input::MouseCallback);
    glfwSetScrollCallback(_window, Input::MouseScrollCallback);
}

AppSetting& Gapp::GetAppSetting()
{
    return _setting;
}

void Gapp::BeforeRenderPhase()
{
    if (_scene != nullptr)
        _scene->Init();
}

void Gapp::RenderPhase()
{
    while (!glfwWindowShouldClose(_window))
    {
        Time::Update();

        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(_window, true);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (_scene != nullptr)
            _scene->Render();

        glfwPollEvents();
        glfwSwapBuffers(_window);
    }
}

void Gapp::CleanUp()
{
    if (_scene != nullptr)
        _scene->Clean();

    glfwTerminate();
}
