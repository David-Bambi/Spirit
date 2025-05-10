#ifndef MODELDEF_HPP
#define MODELDEF_HPP

#include <def/MeshDef.hpp>
#include <model/Model.hpp>
#include <model/ModelBuilder.hpp>
#include <memory>

namespace ModelDef
{
const std::shared_ptr<Model> Triangle01Model =
    ModelBuilder::GetInstance().WithMesh(MeshDef::Triangle01Mesh).BuildShared();

const std::shared_ptr<Model> Rectangle01Model = ModelBuilder::GetInstance()
    .WithMesh(MeshDef::Rectangle01Mesh)
    .WithPosition({4.0f, 0.0f, 0.0f}).BuildShared();

const std::shared_ptr<Model> Cube01Model = ModelBuilder::GetInstance()
    .WithMesh(MeshDef::Cube01Mesh)
    .WithPosition({2.0f, 0.0f, 0.0f}).BuildShared();
};

#endif