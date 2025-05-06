#ifndef MODELDEF_HPP
#define MODELDEF_HPP

#include <def/MeshDef.hpp>
#include <model/Model.hpp>
#include <model/ModelBuilder.hpp>
#include <memory>

namespace ModelDef
{
const std::unique_ptr<Model> ColorRGBTriangle =
    ModelBuilder::GetInstance().WithMesh(MeshDef::ColorRGBTriangle);
};

#endif