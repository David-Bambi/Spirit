#include <GF_C/GF2DCircle.hpp>

GF2DCircle::GF2DCircle(unsigned int shaderprogram, float smoothing,
                       GFColor color, unsigned int texture,
                       unsigned int usage) {
  VectorStruc VecStr = {};
  VecStr.Position = Vec3_f{0.0f, 0.0f, 0.0f};
  VecStr.Color = Vec3_f{color.Red(), color.Green(), color.Blue()};
  VecStr.Tex = Vec3_f{0.0f, 0.0f, 0.0f};
  VecStr.Normal = Vec3_f{0.0f, 0.0f, -1.0f};

  this->vertices.push_back(VecStr); // Center of the circle

  unsigned int index = 1;
  for (float angle = 0.0f; angle <= 360.0f; angle += (1 * smoothing)) {

    float rad = (angle * M_PI) / 180;

    VectorStruc VecStr = {};
    VecStr.Position = Vec3_f{sinf(rad), cosf(rad), 0};
    VecStr.Color = Vec3_f{color.Red(), color.Green(), color.Blue()};
    VecStr.Tex = Vec3_f{sinf(rad), cosf(rad), 0};
    VecStr.Normal = Vec3_f{0.0f, 0.0f, -1.0f};

    this->vertices.push_back(VecStr); // Position

    if (index > 1)
      this->indices.push_back(Vec3_ui{0, index - 1, index}); // Index

    ++index;
  }

  this->color = color;
  this->_shaderprogram = shaderprogram;
  this->_tex = texture;
  this->_usage = GL_STATIC_DRAW;

  this->T = glm::mat4(1.0f);
  this->V = glm::mat4(1.0f);

  this->PrepareRendering();
}

void GF2DCircle::PrepareRendering() {
  unsigned int VBO, VAO, EBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  float vertices_in_array[this->vertices.size() * 11];
  unsigned int index_in_array[this->indices.size() * 3];

  int j = 0;
  for (int i = 0; i < this->vertices.size(); i++) {
    vertices_in_array[j] = this->vertices[i].Position.x;
    // std::cout << vertices_in_array[j] << " ,";
    j++;

    vertices_in_array[j] = this->vertices[i].Position.y;
    // std::cout << vertices_in_array[j] << " ,";

    j++;
    vertices_in_array[j] = this->vertices[i].Position.z;
    // std::cout << vertices_in_array[j] << std::endl;

    j++;
    vertices_in_array[j] = this->vertices[i].Color.x;
    // std::cout << vertices_in_array[j] << std::endl;

    j++;
    vertices_in_array[j] = this->vertices[i].Color.y;
    // std::cout << vertices_in_array[j] << std::endl;

    j++;
    vertices_in_array[j] = this->vertices[i].Color.z;
    // std::cout << vertices_in_array[j] << std::endl;

    j++;
    vertices_in_array[j] = this->vertices[i].Tex.x;
    // std::cout << vertices_in_array[j] << std::endl;

    j++;
    vertices_in_array[j] = this->vertices[i].Tex.y;
    // std::cout << vertices_in_array[j] << std::endl;

    j++;
    vertices_in_array[j] = this->vertices[i].Normal.x;
    // std::cout << vertices_in_array[j] << std::endl;

    j++;
    vertices_in_array[j] = this->vertices[i].Normal.y;
    // std::cout << vertices_in_array[j] << std::endl;

    j++;
    vertices_in_array[j] = this->vertices[i].Normal.z;
    // std::cout << vertices_in_array[j] << std::endl;

    j++;
  }

  j = 0;
  for (int i = 0; i < this->indices.size(); i++) {
    index_in_array[j] = this->indices[i].x;
    // std::cout << index_in_array[j] << " ,";

    j++;
    index_in_array[j] = this->indices[i].y;
    //    std::cout << index_in_array[j] << " ,";

    j++;
    index_in_array[j] = this->indices[i].z;
    //  std::cout << index_in_array[j] << std::endl;

    j++;
  }

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_in_array), vertices_in_array,
               GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index_in_array), index_in_array,
               this->_usage);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float),
                        (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float),
                        (void *)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

  glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float),
                        (void *)(8 * sizeof(float)));
  glEnableVertexAttribArray(3);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  this->_vbo = VBO;
  this->_vao = VAO;
  this->_ebo = EBO;
}

void GF2DCircle::Draw() {
  if (this->_tex > 0) {
    glBindTexture(GL_TEXTURE_2D, this->_tex);
    glUniform1i(glGetUniformLocation(this->_shaderprogram, "hasTex"),
                (int)true);
  } else {
    glUniform1i(glGetUniformLocation(this->_shaderprogram, "hasTex"),
                (int)false);
  }

  unsigned int transformLoc =
      glGetUniformLocation(this->_shaderprogram, "model");
  glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(this->T));

  glBindVertexArray(this->_vao);
  glDrawElements(GL_TRIANGLES, (this->indices.size()) * 3, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}

GFColor GF2DCircle::Color() { return this->color; }
void GF2DCircle::Color(GFColor color) { this->color = color; }

unsigned int GF2DCircle::ShaderType() { return this->_shaderType; }
