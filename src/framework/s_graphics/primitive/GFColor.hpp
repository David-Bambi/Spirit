#ifndef GFCOLOR_HPP
#define GFCOLOR_HPP

class GFColor
{
private:
  float _red = 0;
  float _green = 0;
  float _blue = 0;
  float _opacity = 1;
public:
  GFColor();
  GFColor(float red, float green, float blue, float opacity);
  float Red();
  float Green();
  float Blue();
  float Opacity();  
};

namespace Color
{
  const GFColor Black = GFColor(0.0f, 0.0f, 0.0f, 1.0f);
  const GFColor Red   = GFColor(1.0f, 0.0f, 0.0f, 1.0f);
  const GFColor Green = GFColor(0.0f, 1.0f, 0.0f, 1.0f);
  const GFColor Blue  = GFColor(0.0f, 0.0f, 1.0f, 1.0f);
  const GFColor White  = GFColor(1.0f, 1.0f, 1.0f, 1.0f);


}

#endif
