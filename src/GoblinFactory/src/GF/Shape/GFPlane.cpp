#include <GF/Shape/GFPlane.hpp>

GFPlane::GFPlane()
{
  unsigned int VBO, VAO, EBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  // Order of the vertices
  //            0 __________ 1
  //             |          |
  //             |          | 
  //             |          |
  //             |__________|
  //            2            3

  float vertices [] =
    {
    // Position ------- Texture ---- Normal
    // 
   -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f,  // 0
    0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,  // 1
   -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,  // 2
    0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f   // 3
    };

  unsigned int indices[] = {0, 1, 3,   // first triangle
                            0, 2, 3};  // second triangle
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER,
               sizeof(vertices),
               vertices,
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               sizeof(indices),
               indices,
               GL_STATIC_DRAW); 

  // Vertices
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Texture
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3* sizeof(float)));
  glEnableVertexAttribArray(1);

  // Normal
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5* sizeof(float)));
  glEnableVertexAttribArray(2);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  this->_vbo = VBO;
  this->_vao = VAO;
  this->_ebo = EBO;
}

void GFPlane::Render()
{
  glBindVertexArray(this->_vao);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}