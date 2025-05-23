#ifndef MESHDEF_HPP
#define MESHDEF_HPP

#include <mesh/Mesh.hpp>
#include <mesh/MeshBuilder.hpp>
#include <mesh/VerticesDef.hpp>
#include <color/ColorDef.hpp>

namespace MeshDef
{
    const std::shared_ptr<Mesh> Triangle01Mesh =
        MeshBuilder::GetInstance()
            .WithVertices(VerticesDef::TriangleV)
            .WithColor({Color::Red, Color::Green, Color::Blue})
            .BuildShared();

    const std::shared_ptr<Mesh> Rectangle01Mesh =
        MeshBuilder::GetInstance()
            .WithVertices(VerticesDef::RectangleV)
            .WithIndexs(VerticesDef::RectangleI)
            .WithColor({Color::Red, Color::Green, Color::Blue, Color::Magenta})
            .BuildShared();

    const std::shared_ptr<Mesh> Cube01Mesh =
        MeshBuilder::GetInstance()
            .WithVertices(VerticesDef::CubeV)
            .WithIndexs(VerticesDef::CubeI)
            .WithColor({Color::Red, 
                        Color::Green,
                        Color::Black, 
                        Color::White,
                        Color::Magenta,
                        Color::Blue,
                        Color::Cyan,
                        Color::Yellow})
            .BuildShared();

    const std::shared_ptr<Mesh> Circle01Mesh =
            MeshBuilder::GetInstance()
                .WithVertices(std::move(VerticesDef::CircleV(10)))
                .WithIndexs(std::move(VerticesDef::CircleI(10)))
                .BuildShared();
}

#endif