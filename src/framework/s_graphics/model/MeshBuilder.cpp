#include <model/MeshBuilder.hpp>

MeshBuilder &MeshBuilder::GetInstance() {
  return static_cast<MeshBuilder &>(Builder<Mesh>::GetInstance());
}

MeshBuilder &MeshBuilder::WithVertices(std::vector<glm::vec3> Vertices) {
  _obj->MeshVertices.SetPosition(Vertices);
  return *this;
}

MeshBuilder &MeshBuilder::WithColor(std::vector<Color_t> Color) {
  _obj->MeshVertices.SetColor(Color);
  return *this;
}

MeshBuilder &MeshBuilder::WithTextureCoord(std::vector<glm::vec2> TexCoord) {
  _obj->MeshVertices.SetTexture(TexCoord);
  return *this;
}

MeshBuilder &MeshBuilder::WithTexture(std::unique_ptr<Texture> Tex) {
  _obj->_textures.push_back(std::move(Tex));
  return *this;
}

MeshBuilder &MeshBuilder::WithIndexs(std::vector<unsigned int> indexs) {
  _obj->MeshVertices.Indexs = indexs;
  return *this;
}

MeshBuilder &MeshBuilder::WithShader(unsigned int ShaderId) {
  _obj->_shaderId = ShaderId;
  return *this;
}