#ifndef GF2DSCENE_HPP
#define GF2DSCENE_HPP

#include <vector>
#include <map>

#include <GF_C/GFScene.hpp>
#include <GF_C/GFShader.hpp>



class GF2DScene : public GFScene
{
protected :
  unsigned int _shaderId;
  unsigned int _shaderLightId;
public:
  GF2DScene();
  virtual void Build();
};

#endif
