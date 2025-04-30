#include <texture/TextureBuilder.hpp>

TextureBuilder &TextureBuilder::GetInstance() {
  return static_cast<TextureBuilder &>(Builder<Texture>::GetInstance());
}

/**
 * @brief Set the texture path of the texture builder
 *
 * @param Path
 * @return TextureBuilder&
 */
TextureBuilder &TextureBuilder::WithPath(const char *Path) {
  _obj->_path = Path;
  return *this;
}

/**
 * @brief Set the  image load setting of the texture
 *
 * @param Path
 * @return TextureBuilder&
 */
TextureBuilder &TextureBuilder::WithImagLoadSetting(ILS ils) {
  _obj->_ILS = ils;
  return *this;
}
