#include <GF_C/GFWindow.hpp>

GFWindow::GFWindow(int height,
                   int width,
                   const char* title,
                   GFColor* bgColor,
                   bool canResizeViewPort)
  : Window(height, width, title),
    _bgColor(bgColor)
{}

void GFWindow::Draw()
{
  this->ProcessInput();
  glClearColor(this->_bgColor->Red(),
               this->_bgColor->Green(),
               this->_bgColor->Blue(),
               this->_bgColor->Opacity());
  
  glClear(GL_COLOR_BUFFER_BIT);
}

GFColor* GFWindow::GetBgColor()
{
  return this->_bgColor;
}
  
void GFWindow::SetBgColor(GFColor* bgColor)
{
  this->_bgColor = bgColor;
}
