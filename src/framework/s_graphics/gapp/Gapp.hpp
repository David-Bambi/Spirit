#ifndef GAPP_HPP
#define GAPP_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <gapp/GAppSetting.hpp>
#include <object/Object.hpp>
#include <gobject/UGID.hpp>
#include <tsl/robin_set.h>
#include <memory>

/**
 * @brief Graphic application class
 */
class Gapp : public Object
{
  public:
    /** Run the graphics application. */
    void Run();

    /** Getter */
    GAppSetting& GetSetting();
    GID_t GetDefaultScene() const;
    const tsl::robin_set<GID_t>& GetScenes() const;

    /** Current graphic application */
    static std::unique_ptr<Gapp> CurrentGapp;

  private:
    /** Default graphic application setting */
    GAppSetting _setting = {"Graphic application", 640, 480, false, true};

    /** Windows context */
    GLFWwindow* _window = nullptr;

    /** Scene at start */
    GID_t _default_scene = -1;

    /** Scene for graphic application */
    tsl::robin_set<GID_t> _scenes = {};

    /** Set the window and the context for opengl */
    void InitContext();

    /** Initialize the graphic application like scene */
    void InitPhase();

    /** Render the scene */
    void RenderPhase();

    /** Cela graphic application */
    void CleanPhase();

    friend class GappBuilder;
};

#endif