#ifndef TEXTUREBUILDER_HPP
#define TEXTUREBUILDER_HPP

#include <texture/Texture.hpp>

#include <memory>
#include <builder/Builder.hpp>

class TextureBuilder : public Builder<Texture>
{
    public :
        TextureBuilder& WithPath(const char* Path);
        TextureBuilder& WithImagLoadSetting(ILS ils);

        static TextureBuilder& GetInstance();
};

#endif