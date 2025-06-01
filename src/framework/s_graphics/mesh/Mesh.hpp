#ifndef MESH_HPP
#define MESH_HPP

#include <glm/glm.hpp>
#include <memory>
#include <mesh/Vertices.hpp>
#include <object/Object.hpp>
#include <texture/Texture.hpp>
#include <vector>

class Mesh : public Object
{
  public:
    void Init(unsigned int progshader);
    void Render();
    void Clean();

    void Transform(glm::mat4 transform);

  protected:
    void SetupTexture();
    void ActiveAndBindTexture();
    void ProcessTransform();

  private:
    unsigned int _vao = 0;
    unsigned int _vbo = 0;
    unsigned int _ebo = 0;
    unsigned int _tex = 0;

    unsigned int _shaderId = 0;
    Vertices MeshVertices = {};

    std::vector<std::shared_ptr<Texture>> _textures = {};
    glm::mat4 _transform = glm::mat4(1.0f);

    friend class MeshBuilder;
};

#endif