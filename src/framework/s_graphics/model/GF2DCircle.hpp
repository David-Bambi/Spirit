/**
 * @class GF2DCircle
 * @author David Boivin
 * Object that represent a primitive circle to be draw.
 * **/

#ifndef GF2DCIRCLE_HPP
#define GF2DCIRCLE_HPP

#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

#include <GF_C/GFColor.hpp>
#include <GF_C/GFData.hpp>
#include <GF_C/GFDraw_I.hpp>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct VectorStruc {
  Vec3_f Position;
  Vec3_f Color;
  Vec3_f Tex;
  Vec3_f Normal;
};

class GF2DCircle : public GFDraw_I {
private:
  std::vector<struct VectorStruc> vertices;
  std::vector<Vec3_ui> indices;

  unsigned int _vao;
  unsigned int _vbo;
  unsigned int _ebo;
  unsigned int _usage;
  unsigned int _shaderprogram;
  unsigned int _tex;

  GFColor color;
  unsigned int _shaderType;
  void PrepareRendering();

public:
  /** Model transformation matrix **/
  glm::mat4 T;
  /** View matrix **/
  glm::mat4 V;
  /** Projection matrix **/
  glm::mat4 P;

  GF2DCircle(unsigned int shaderprogram, float smoothing = 1.0f,
             GFColor color = Color::Black, unsigned int texture = 0,
             unsigned int usage = GL_STATIC_DRAW);

  virtual void Draw();
  virtual unsigned int ShaderType();
  GFColor Color();
  void Color(GFColor color);
};

#endif
