#include <GF_C/GF2DScene.hpp>

GF2DScene::GF2DScene(){};

void GF2DScene::Build()
{
  GFShader shader("shaders/shader2D.vs",
                  "shaders/shader2D.fs");

  GFShader shaderLight("shaders/shaderLight.vs",
                      "shaders/shaderLight.fs");

  this->_shaderId = shader.Id();
  this->_shaderLightId = shaderLight.Id();
 
  this->DrawingObjects.insert(std::pair<unsigned int,std::vector<GFDraw_I*>>
                              (shader.Id(), std::vector<GFDraw_I*>()));
  this->DrawingObjects.insert(std::pair<unsigned int,std::vector<GFDraw_I*>>
                            (shaderLight.Id(), std::vector<GFDraw_I*>()));
}
