#include <texture/TextureBuilder.hpp>

#include <iostream>
#include <stdexcept>

TextureBuilder& TextureBuilder::GetInstance()
{
    static TextureBuilder instance;
    return instance;
}

/**
 * @brief Set the texture path of the texture builder
 *
 * @param Path
 * @return TextureBuilder&
 */
TextureBuilder& TextureBuilder::WithPath(const char* Path)
{
    _obj->_path = Path;
    return *this;
}

/**
 * @brief Set the  image load setting of the texture
 *
 * @param Path
 * @return TextureBuilder&
 */
TextureBuilder& TextureBuilder::WithImagLoadSetting(ImgLoadSetting ils)
{
    _obj->_ils = ils;
    return *this;
}
