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
const std::shared_ptr<Scene> ShapeScene =
    SceneBuilder::GetInstance()
        .WithModel(ModelDef::Triangle01Model, ProgramShaderDef::Program01)
        .WithModel(ModelDef::Rectangle01Model, ProgramShaderDef::Program01)
        .WithModel(ModelDef::Cube01Model, ProgramShaderDef::Program01)
        .WithModel(ModelDef::Circle01Model, ProgramShaderDef::Program02)
        .WithCamera(CameraDef::Cam01)
        .BuildShared();
};

#endif