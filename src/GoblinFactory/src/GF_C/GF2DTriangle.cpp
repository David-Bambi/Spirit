#include <GF_C/GF2DTriangle.hpp>

GF2DTriangle::GF2DTriangle(unsigned int shaderprogram,
                           GFColor color,
                           unsigned int texture,
                           unsigned int usage)
{
  this->_shaderprogram = shaderprogram;
  
  // Set the color
  this->_red_v1 = color.Red();
  this->_red_v2 = color.Red();
  this->_red_v3 = color.Red();
  this->_green_v1 = color.Green();
  this->_green_v2 = color.Green();
  this->_green_v3 = color.Green();
  this->_blue_v1 = color.Blue();
  this->_blue_v2 = color.Blue();
  this->_blue_v3 = color.Blue();

  this->_tex = texture;
  this->T = glm::mat4(1.0f);
  this->V = glm::mat4(1.0f);
  this->_usage = usage;  
  this->PrepareRendering();
};

void GF2DTriangle::PrepareRendering()
{
  unsigned int VBO, VAO, TEX;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  
  glBindVertexArray(VAO);

  float vertices [] =
    {// Position           Color                                          Texture
     -1.0f, -1.0f, 0.0f, this->_red_v1, this->_green_v1, this->_blue_v1, 0.0f, 0.0f, 0.0f,0.0f,-1.0f,
     1.0f, -1.0f, 0.0f, this->_red_v2, this->_green_v2, this->_blue_v2, 1.0f, 0.0f, 0.0f,0.0f,-1.0f,
     0.0f,  1.0f, 0.0f, this->_red_v3, this->_green_v3, this->_blue_v3, 0.5f, 1.0f, 0.0f,0.0f,-1.0f
    };
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(vertices),
               vertices,
               this->_usage);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);  
  
  glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8* sizeof(float)));
  glEnableVertexAttribArray(3);


  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  this->_vbo = VBO;
  this->_vao = VAO;
}

void GF2DTriangle::Draw()
{  
  if(this->_tex > 0)
    {
      glBindTexture(GL_TEXTURE_2D, this->_tex);
      glUniform1i(glGetUniformLocation(this->_shaderprogram, "hasTex"), (int)true);
    }
  else
    {
      glUniform1i(glGetUniformLocation(this->_shaderprogram, "hasTex"), (int)false);
  }
  unsigned int transformLoc = glGetUniformLocation(this->_shaderprogram, "model");
  glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(this->T));

  glBindVertexArray(this->_vao);
  glDrawArrays(GL_TRIANGLES, 0, 3);
  glBindVertexArray(0);
}

