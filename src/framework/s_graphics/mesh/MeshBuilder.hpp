#ifndef MESHBUILDER_HPP
#define MESHBUILDER_HPP

#include <builder/Builder.hpp>
#include <memory>
#include <mesh/Mesh.hpp>
#include <texture/Texture.hpp>

/**
 * @brief Helper class to build mesh
 *
 */
class MeshBuilder : public Builder<Mesh>
{
  public:
    static MeshBuilder& GetInstance();

    MeshBuilder& WithVertices(const std::vector<glm::vec3>& Vertices);
    MeshBuilder& WithColor(std::vector<Color_t> Color);
    MeshBuilder& WithTexture(const std::shared_ptr<Texture>& Tex);
    MeshBuilder& WithTextureCoord(const std::vector<glm::vec2>& TexCoord);
    MeshBuilder& WithIndexs(std::vector<unsigned int>& indexs);
    MeshBuilder& WithShader(unsigned int ShaderId);
};

#endif