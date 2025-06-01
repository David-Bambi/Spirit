#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glad/glad.h>
#include <texture/ImgLoadSetting.hpp>
#include <object/Object.hpp>

class Texture : public Object
{
  private:
    const char* _path = nullptr;
    GLuint _tex = 0;
    ImgLoadSetting _ils = {false};

    void ProcessILS();

  public:
    void GenerateTexture();
    unsigned int Id();

    friend class TextureBuilder;
};

#endif