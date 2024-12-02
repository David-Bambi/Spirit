#include <GF_C/GFColor.hpp>

GFColor::GFColor(){};

GFColor::GFColor(float red, float green, float blue, float opacity)
  : _red(red),
    _green(green),
    _blue(blue),
    _opacity(opacity)
{}

float GFColor::Red()
{
  return this->_red;
}

float GFColor::Green()
{
  return this->_green;
}

float GFColor::Blue()
{
  return this->_blue;
}

float GFColor::Opacity()
{
  return this->_opacity;
}
