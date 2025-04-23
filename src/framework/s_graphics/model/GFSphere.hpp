#ifndef GFSPHERE_HPP
#define GFSPHERE_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <GF/Shape/Renderable.hpp>

class GFSphere : public Renderable
{
private :
  unsigned int _vao;
  unsigned int _vbo;
  unsigned int _ebo; 

public :

  GFSphere(int radius, int n);
  virtual void Render();
};

#endif 