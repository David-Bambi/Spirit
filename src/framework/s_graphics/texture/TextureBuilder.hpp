#ifndef TEXTUREBUILDER_HPP
#define TEXTUREBUILDER_HPP

#include <texture/Texture.hpp>

#include <builder/Builder.hpp>
#include <memory>

class TextureBuilder : public Builder<Texture>
{
  public:
    TextureBuilder& WithPath(const char* Path);
    TextureBuilder& WithImagLoadSetting(ImgLoadSetting ils);

    static TextureBuilder& GetInstance();
};

#endif