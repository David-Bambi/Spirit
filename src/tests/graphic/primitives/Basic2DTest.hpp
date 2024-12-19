#ifndef BASIC2DTEST_HPP
#define BASIC2DTEST_HPP

#include <GF_C/GF2DScene.hpp>
#include <GF_C/GF2DRectangle.hpp>
#include <GF_C/GF2DCube.hpp>
#include <GF_C/GF2DTriangle.hpp>
#include <GF_C/GF2DCircle.hpp>
#include <GF_C/GFCamera.hpp>

#include <GF_C/GFTexture.hpp>
#include <GLFW_C/Window.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Basic2DTest : public GF2DScene
{
private :
  Window* _window;
public :
  Basic2DTest(Window* window);
  void Build();

private :
static void OnKeyEvent(GLFWwindow* window,
                       int         key,
                       int         scancode,
                       int         action,
                       int         mods);

static void OnMousePosEvent(GLFWwindow* window, 
                            double xpos, 
                            double ypos);
static void OnScrollEvent(GLFWwindow *window, 
                          double     xoffset, 
                          double     yoffset);
};

#endif