#include <glad/glad.h>
#include <iostream>
#include <stb_image/stb_image.h>
#include <texture/Texture.hpp>

Texture::Texture() { glGenTextures(1, &_TEX); }

Texture::~Texture() {}

unsigned int Texture::Id() { return _TEX; }

void Texture::GenerateTexture() {
  glBindTexture(GL_TEXTURE_2D, _TEX);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  ProcessILS();

  int width, height, nrChannels;
  unsigned char *data = stbi_load(_path, &width, &height, &nrChannels, 0);

  if (data) {
    if (nrChannels > 3)
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA,
                   GL_UNSIGNED_BYTE, data);
    else
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                   GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }

  stbi_image_free(data);
}

void Texture::ProcessILS() {
  stbi_set_flip_vertically_on_load(_ILS.flip_vertical);
}