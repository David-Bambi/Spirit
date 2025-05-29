#ifndef VERTICES_HPP
#define VERTICES_HPP

#include <bitset>
#include <glm/glm.hpp>
#include <mesh/Vertex.hpp>
#include <vector>

/**
 * @brief Class to manage the vertices of a mesh object.
 */
class Vertices
{
  public:
    void SetPosition(const std::vector<glm::vec3>& position);
    void SetColor(std::vector<Color_t> color);
    void SetTexture(const std::vector<glm::vec2>& TexCoord);
    const std::vector<float> VerticesVec();
    const std::vector<unsigned int> Indexs();
    void SetIndexs(const std::vector<unsigned int>& indexs);
    unsigned int Count();

    void Build();
    void SetVertexAttrPtr();

  private:
    struct Offset
    {
        size_t pos;
        size_t nor;
        size_t tex;
        size_t col;
    };

    int _stride = 0;
    Offset _offset = {0, 0, 0, 0};
    std::bitset<4> _vertextype = 0b0000;
    unsigned int _count = 0;

    std::vector<Color_t> _col = {};
    std::vector<glm::vec3> _pos = {};
    std::vector<glm::vec2> _tex = {};

    std::vector<float> _vertices_vec = {};
    std::vector<unsigned int> _indexs = {};

    void InitVertexInfo();

    friend class Mesh;
};

#endif
