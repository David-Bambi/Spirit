#include <GF/GFTexture.hpp>

GFTexture::GFTexture(const char* path)
{
  int width, height, nrChannels;
  unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);

  unsigned int TEX;
  glGenTextures(1, &TEX);
  glBindTexture(GL_TEXTURE_2D, TEX);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


  if (data)
    {
      glTexImage2D(GL_TEXTURE_2D,
                   0,
                   GL_RGB,
                   width,
                   height,
                   0,
                   GL_RGB,
                   GL_UNSIGNED_BYTE,
                   data);
          
      glGenerateMipmap(GL_TEXTURE_2D);
    }
  else
    {
      std::cout << "Failed to load texture" << std::endl;
    }
  glBindTexture(GL_TEXTURE_2D, 0);
  this->_tex = TEX;
  stbi_image_free(data);
}

unsigned int GFTexture::Id()
{
  return this->_tex;
}
