#ifndef MESHDEF_HPP
#define MESHDEF_HPP

#include <mesh/Mesh.hpp>
#include <mesh/MeshBuilder.hpp>
#include <mesh/VerticesDef.hpp>

namespace MeshDef
{
std::unique_ptr<Mesh> ColorRGBTriangle = MeshBuilder::GetInstance()
                                             .WithVertices(VerticesDef::TriangleV)
                                             .WithColor({Color::Red, Color::Green, Color::Blue})
                                             .Build();
}

#endif