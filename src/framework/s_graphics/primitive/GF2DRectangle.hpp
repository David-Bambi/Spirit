#ifndef GF2DRECTANGLE_HPP
#define GF2DRECTANGLE_HPP

#include <glad/glad.h>
#include <GF_C/GFDraw_I.hpp>
#include <GF_C/GFColor.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GF2DRectangle : public GFDraw_I
{
private :
  unsigned int _vao;
  unsigned int _vbo;
  unsigned int _ebo;
  unsigned int _usage;
  unsigned int _shaderprogram;
  unsigned int _tex;
  
  // Color vertex 1 (right top)
  float _red_v1;
  float _green_v1;
  float _blue_v1;

  // Color vertex 2 (left top)
  float _red_v2;
  float _green_v2;
  float _blue_v2;

  // Color vertex 3 (right bottom)
  float _red_v3;
  float _green_v3;
  float _blue_v3;

  // Color vertex 4 (left bottom)
  float _red_v4;
  float _green_v4;
  float _blue_v4;
  
  void PrepareRendering();

public :
  /** Model transformation matrix **/
  glm::mat4 T; 
  /** View matrix **/
  glm::mat4 V;  
  /** Projection matrix **/
  glm::mat4 P;
  
  GF2DRectangle(unsigned int shaderprogram,
               GFColor color = Color::Black,
               unsigned int texture = 0,
               unsigned int usage = GL_STATIC_DRAW);
  


  virtual void Draw();
  };


#endif 
