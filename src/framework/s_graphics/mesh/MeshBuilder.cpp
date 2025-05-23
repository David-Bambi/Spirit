#include <mesh/MeshBuilder.hpp>

#include <iostream>
#include <debug/Tracer.hpp>

MeshBuilder& MeshBuilder::GetInstance()
{
    static MeshBuilder instance;
    return instance;
}

MeshBuilder& MeshBuilder::WithVertices(const std::vector<glm::vec3>& Vertices)
{
    _obj->MeshVertices.SetPosition(Vertices);
    return *this;
}

MeshBuilder& MeshBuilder::WithColor(std::vector<Color_t> Color)
{
    _obj->MeshVertices.SetColor(std::move(Color));
    return *this;
}

MeshBuilder& MeshBuilder::WithTextureCoord(const std::vector<glm::vec2>& TexCoord)
{
    _obj->MeshVertices.SetTexture(TexCoord);
    return *this;
}

MeshBuilder& MeshBuilder::WithTexture(const std::shared_ptr<Texture>& Tex)
{
    _obj->_textures.push_back(Tex);
    return *this;
}

MeshBuilder& MeshBuilder::WithIndexs(const std::vector<unsigned int>& indexs)
{
    _obj->MeshVertices.SetIndexs(indexs);
    return *this;
}

MeshBuilder& MeshBuilder::WithShader(unsigned int ShaderId)
{
    _obj->_shaderId = ShaderId;
    return *this;
}