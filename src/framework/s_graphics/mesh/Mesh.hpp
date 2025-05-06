#ifndef MESH_HPP
#define MESH_HPP

#include <memory>
#include <vector>

#include <model/Vertices.hpp>
#include <texture/Texture.hpp>

#include <glm/glm.hpp>

class Mesh
{
  public:
    Mesh();
    virtual ~Mesh();
    Mesh(const Mesh& other) = default;
    Mesh(Mesh&& other) noexcept = default;
    Mesh& operator=(const Mesh& other) = default;
    Mesh& operator=(Mesh&& other) noexcept = default;

    virtual void Setup();
    virtual void Render();

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

    std::vector<std::unique_ptr<Texture>> _textures = {};
    glm::mat4 _transform = glm::mat4(1.0f);

    friend class MeshBuilder;
};

#endif