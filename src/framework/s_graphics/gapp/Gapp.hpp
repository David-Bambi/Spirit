#ifndef GAPP_HPP
#define GAPP_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <gapp/AppSetting.hpp>
#include <object/Object.hpp>
#include <memory>

class Gapp : public Object
{
  public:
    void Init();
    void Run();
    void Shutdown();

  private:
    AppSetting _setting = {"Graphic application", 640, 480};
    GLFWwindow* _window = nullptr;

    friend class GappBuilder;
};

#endif