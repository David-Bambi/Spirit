#ifndef SCENEDEF_HPP
#define SCENEDEF_HPP

#include <scene/Scene.hpp>
#include <scene/SceneBuilder.hpp>
#include <memory>
#include <def/ModelDef.hpp>
#include <def/ProgramShaderDef.hpp>
#include <def/CameraDef.hpp>

namespace SceneDef
{
const std::shared_ptr<Scene> ShapeScene = SceneBuilder::GetInstance()
                                              .WithModel(ModelDef::Triangle01Model)
                                              .WithModel(ModelDef::Rectangle01Model)
                                              .WithModel(ModelDef::Cube01Model)
                                              .WithCamera(CameraDef::Cam01)
                                              .WithProgramShader(ProgramShaderDef::Program01)
                                              .BuildShared();
};

#endif