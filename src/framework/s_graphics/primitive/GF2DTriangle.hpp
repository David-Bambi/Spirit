#ifndef GF2DTRIANGLE_HPP
#define GF2DTRIANGLE_HPP

#include <glad/glad.h>
#include <iostream>

#include <GF_C/GFColor.hpp>
#include <GF_C/GFDraw_I.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GF2DTriangle : public GFDraw_I
{
private :
  unsigned int _vao;
  unsigned int _vbo;
  unsigned int _usage;
  unsigned int _tex;
  unsigned int _shaderprogram;
  
  // Color vertex 1 (right bottom)
  float _red_v1;
  float _green_v1;
  float _blue_v1;

  // Color vertex 2 (left bottom)
  float _red_v2;
  float _green_v2;
  float _blue_v2;

  // Color vertex 3 (middle top)
  float _red_v3;
  float _green_v3;
  float _blue_v3;
  
  void PrepareRendering();

public :  
  /** Model transformation matrix **/
  glm::mat4 T; 
  /** View matrix **/
  glm::mat4 V;  
  /** Projection matrix **/
  glm::mat4 P;

  GF2DTriangle(unsigned int shaderprogram,
               GFColor color = Color::Black,
               unsigned int texture = 0,
               unsigned int usage = GL_STATIC_DRAW);
  
  virtual void Draw();
};


#endif 
