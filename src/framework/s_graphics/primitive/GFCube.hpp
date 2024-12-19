#ifndef GFCUBE_HPP
#define GFCUBE_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GFCube
{
private :
  unsigned int _vao;
  unsigned int _vbo;
    
public :

  GFCube();
  virtual void Render();
};

#endif 