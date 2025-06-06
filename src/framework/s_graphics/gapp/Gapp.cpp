#include <gapp/Gapp.hpp>

#include <input/Input.hpp>
#include <time/Time.hpp>
#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>

std::unique_ptr<Gapp> Gapp::CurrentGapp = nullptr;

void Gapp::Run()
{
    Gapp::CurrentGapp = std::make_unique<Gapp>(*this);
    InitContext();
    InitPhase();
    RenderPhase();
    CleanPhase();
}

GAppSetting& Gapp::GetSetting()
{
    return _setting;
}

GID_t Gapp::GetDefaultScene() const
{
    return _default_scene;
}

const tsl::robin_set<GID_t>& Gapp::GetScenes() const
{
    return _scenes;
}

void Gapp::InitContext()
{
    uglfw::InitializeGlfw();
    _window = uglfw::CreateWinContext(_setting.SCREEN_WIDTH, 
                                      _setting.SCREEN_HEIGHT, 
                                      _setting.APP_NAME.c_str());
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

void Gapp::InitPhase()
{
    if (_default_scene != -1)
        return;
        //_default_scene->Init();
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

        if (_default_scene != -1)
            ;

        glfwPollEvents();
        glfwSwapBuffers(_window);
    }
}

void Gapp::CleanPhase()
{
    if (_default_scene != -1)
        return;

    glfwTerminate();
}
