#ifndef GFTEXTURE_HPP
#define GFTEXTURE_HPP

#include <iostream>
#include <glad/glad.h>
#include <stb_image.h>

class GFTexture
{
private:
  unsigned int _tex;
public:
  GFTexture();
  GFTexture(const char* path);
  unsigned int Id(); 
};

#endif
