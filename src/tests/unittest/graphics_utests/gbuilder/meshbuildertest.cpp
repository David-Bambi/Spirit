#include <catch2/catch_test_macros.hpp>
#include <mesh/Mesh.hpp>
#include <mesh/MeshBuilder.hpp>
#include <memory>

TEST_CASE("Build raw ptr", "[graphics][mesh]") 
{
    MeshBuilder& MB = MeshBuilder::GetInstance();
    Mesh* M = MB.Build();
    
    REQUIRE(M != nullptr);
    delete M;
}

TEST_CASE("Build unique ptr", "[graphics][mesh]") 
{
    MeshBuilder& MB = MeshBuilder::GetInstance();
    std::unique_ptr<Mesh> M = MB.BuildUnique();
    
    REQUIRE(M != nullptr);
}

TEST_CASE("Build shared ptr", "[graphics][mesh]") 
{
    MeshBuilder& MB = MeshBuilder::GetInstance();
    std::shared_ptr<Mesh> M = MB.BuildShared();
    
    REQUIRE(M != nullptr);
}