#ifndef GFSCENE_HPP
#define GFSCENE_HPP

#include <vector>
#include <map>

// GF library 
#include <GF_C/GFCamera.hpp>
#include <GF_C/GFDraw_I.hpp>
#include <GF_C/GFShader.hpp>
#include <GF_C/GFShaderList.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GFScene
{
protected :
  std::map<unsigned int, std::vector<GFDraw_I*>> DrawingObjects;
  
public :
  glm::vec3 lightpos;

  void Draw(float Frame);
  virtual void Build() = 0;
};


#endif
