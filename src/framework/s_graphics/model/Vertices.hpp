#ifndef VERTICES_HPP
#define VERTICES_HPP

#include <bitset>
#include <glm/glm.hpp>
#include <model/Vertex.hpp>
#include <vector>

/**
 * @brief Class to manage the vertices of a mesh object.
 */
class Vertices {
public:
  void SetPosition(std::vector<glm::vec3> position);
  void SetColor(std::vector<Color_t> color);
  void SetTexture(const std::vector<glm::vec2> TexCoord);

  void Build();
  void SetVertexAttrPtr();

  unsigned int Count;
  std::vector<float> Vertices;
  std::vector<unsigned int> Indexs;

private:
  struct Offset {
    size_t pos;
    size_t nor;
    size_t tex;
    size_t col;
  };

  int _stride;
  Offset _offset;
  std::bitset<4> _vertextype;
  std::vector<Color_t> _col;
  std::vector<glm::vec3> _pos;
  std::vector<glm::vec2> _tex;

  void InitVertexInfo();
};

#endif
