#ifndef SCENEDEF_HPP
#define SCENEDEF_HPP

#include <scene/Scene.hpp>
#include <scene/SceneBuilder.hpp>
#include <memory>
#include <model/ModelDef.hpp>

namespace SceneDef
{
const std::unique_ptr<Scene> =
    SceneBuilder::GetInstance().WithModel(ModelDef::ColorRGBTriangle).Build();
};

#endif