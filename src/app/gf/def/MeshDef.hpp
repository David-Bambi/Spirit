#ifndef MESHDEF_HPP
#define MESHDEF_HPP

#include <mesh/Mesh.hpp>
#include <mesh/MeshBuilder.hpp>
#include <mesh/VerticesDef.hpp>
#include <color/ColorDef.hpp>

namespace MeshDef
{
const std::shared_ptr<Mesh> ColorRGBTriangle =
    MeshBuilder::GetInstance()
        .WithVertices(VerticesDef::TriangleV)
        .WithColor({Color::Red, Color::Green, Color::Blue})
        .BuildShared();
}

#endif