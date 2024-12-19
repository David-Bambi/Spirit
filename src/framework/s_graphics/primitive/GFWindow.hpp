#ifndef GFWINDOW_HPP
#define GFWINDOW_HPP

#include <GLFW_C/Window.hpp>
#include <GF_C/GFColor.hpp>

class GFWindow : public Window
{
private:
  GFColor* _bgColor;
public:
  GFWindow(int height,
           int width,
           const char* title,
           GFColor* bgColor,
           bool canResizeViewPort = true);

  virtual void Draw();
  
  GFColor* GetBgColor();
  void     SetBgColor(GFColor* bgColor);
};

#endif
