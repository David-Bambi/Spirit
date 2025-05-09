#ifndef SCENEDEF_HPP
#define SCENEDEF_HPP

#include <scene/Scene.hpp>
#include <scene/SceneBuilder.hpp>
#include <memory>
#include <def/ModelDef.hpp>
#include <def/ProgramShaderDef.hpp>

namespace SceneDef
{
const std::shared_ptr<Scene> ShapeScene = SceneBuilder::GetInstance()
                                              .WithModel(ModelDef::ColorRGBTriangle)
                                              .WithProgramShader(ProgramShaderDef::Program01)
                                              .BuildShared();
};

#endif