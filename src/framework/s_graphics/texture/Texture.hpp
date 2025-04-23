#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <glad/glad.h>
#include <texture/ImgLoadSetting.hpp>

class Texture 
{
    private : 
        const char* _path;
        GLuint _TEX;
        ImgLoadSetting _ILS;

        void ProcessILS();


    public :
        Texture();
        ~Texture();
        void GenerateTexture();
        unsigned int Id();

    friend class TextureBuilder;
};

#endif