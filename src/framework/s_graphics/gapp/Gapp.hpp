#ifndef GAPP_HPP
#define GAPP_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <gapp/AppSetting.hpp>
#include <object/Object.hpp>
#include <scene/Scene.hpp>
#include <memory>

class Gapp : public Object
{
  public:
    void Run();
    AppSetting& GetAppSetting();
    static Gapp* CurrentGapp;

  private:
    AppSetting _setting = {"Graphic application", 640, 480};

    GLFWwindow* _window = nullptr;
    std::shared_ptr<Scene> _scene = {};

    void BeforeRenderPhase();
    void RenderPhase();
    void CleanUp();
    void InitContext();

    friend class GappBuilder;
};

#endif