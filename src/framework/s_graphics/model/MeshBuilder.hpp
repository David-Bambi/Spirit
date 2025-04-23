#ifndef MESHBUILDER_HPP
#define MESHBUILDER_HPP

#include <model/Mesh.hpp>
#include <builder/Builder.hpp>
#include <texture/Texture.hpp>
#include <memory>


/**
 * @brief Helper class to build mesh
 * 
 */
class MeshBuilder : public Builder<Mesh>
{
    public : 
        MeshBuilder& WithVertices(std::vector<glm::vec3>);
        MeshBuilder& WithColor(std::vector<Color_t> Color);
        MeshBuilder& WithTexture(std::unique_ptr<Texture> Tex);
        MeshBuilder& WithTextureCoord(std::vector<glm::vec2> TexCoord);
        MeshBuilder& WithIndexs(std::vector<unsigned int> indexs);
        MeshBuilder& WithShader(unsigned int ShaderId);

    static MeshBuilder& GetInstance();
};

#endif