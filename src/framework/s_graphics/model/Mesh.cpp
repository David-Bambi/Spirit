#include <model/Mesh.hpp>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <stdio.h>
#include <string>
#include <texture/GLTexture.hpp>

Mesh::Mesh() {
  glGenVertexArrays(1, &_VAO);
  glGenBuffers(1, &_VBO);
  glGenBuffers(1, &_EBO);
}

Mesh::~Mesh() {
  glDeleteVertexArrays(1, &_VAO);
  glDeleteBuffers(1, &_VBO);
  glDeleteBuffers(1, &_EBO);
}

void Mesh::Render() {
  glUseProgram(_shaderId);

  ProcessTransform();

  ActiveAndBindTexture();

  glBindVertexArray(_VAO);

  if (MeshVertices.Indexs.size() > 0)
    glDrawElements(GL_TRIANGLES, MeshVertices.Indexs.size(), GL_UNSIGNED_INT,
                   0);
  else
    glDrawArrays(GL_TRIANGLES, 0, MeshVertices.Count);

  glBindVertexArray(0);
}

void Mesh::Setup() {
  MeshVertices.Build();

  glUseProgram(_shaderId);

  glBindVertexArray(_VAO);

  glBindBuffer(GL_ARRAY_BUFFER, _VBO);
  glBufferData(GL_ARRAY_BUFFER, MeshVertices.Vertices.size() * sizeof(float),
               MeshVertices.Vertices.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               MeshVertices.Indexs.size() * sizeof(unsigned int),
               MeshVertices.Indexs.data(), GL_STATIC_DRAW);

  MeshVertices.SetVertexAttrPtr();

  SetupTexture();

  glBindVertexArray(0);
}

void Mesh::SetupTexture() {

  for (int i = 0; i < _textures.size(); i++) {
    std::string texname = "tex" + std::to_string(i);
    glUniform1i(glGetUniformLocation(_shaderId, texname.c_str()), i);

    _textures[i]->GenerateTexture();
  }
}

void Mesh::ActiveAndBindTexture() {
  for (int i = 0; i < _textures.size(); i++) {
    glActiveTexture(GLTexture::gltex[i]);
    glBindTexture(GL_TEXTURE_2D, _textures[i]->Id());
  }
}

void Mesh::Transform(glm::mat4 transform) { _transform = transform; }

void Mesh::ProcessTransform() {
  unsigned int transformLoc = glGetUniformLocation(_shaderId, "transform");
  glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(_transform));
}
