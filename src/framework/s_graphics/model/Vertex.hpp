#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <color/Color_t.hpp>
#include <glm/glm.hpp>

/**
 * @brief Structure to identify the size of the vertices of a mesh.
 *
 * @tparam HasNormal
 * @tparam HasTexture
 * @tparam HasColor
 */
template <bool HasNormal, bool HasTexture, bool HasColor> struct Vertex {
  glm::vec3 position;
  Vertex(glm::vec3 pos) : position(pos) {}
};

template <> struct Vertex<false, false, false> {
  glm::vec3 position;
  Vertex(glm::vec3 pos) : position(pos) {}
};

template <> struct Vertex<false, false, true> {
  glm::vec3 position;
  Color_t color;

  Vertex(glm::vec3 pos, Color_t col) : position(pos), color(col) {}
};

template <> struct Vertex<false, true, true> {
  glm::vec3 position;
  glm::vec2 texture;
  Color_t color;

  Vertex(glm::vec3 pos, glm::vec2 tex, Color_t col)
      : position(pos), texture(tex), color(col) {}
};

template <> struct Vertex<false, true, false> {
  glm::vec3 position;
  glm::vec2 texture;

  Vertex(glm::vec3 pos, glm::vec2 tex) : position(pos), texture(tex) {}
};

using VertexPos = Vertex<false, false, false>;
using VertexPosTex = Vertex<false, true, false>;
using VertexPosCol = Vertex<false, false, true>;
using VertexPosTexCol = Vertex<false, true, true>;

#endif