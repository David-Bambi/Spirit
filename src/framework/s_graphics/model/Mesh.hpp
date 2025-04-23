#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <memory>

#include <model/Vertices.hpp>
#include <texture/Texture.hpp>

#include <glm/glm.hpp>

class Mesh
{
public:
    Mesh();
    ~Mesh();

    virtual void Setup();
    virtual void Render();

    void Transform(glm::mat4 transform);

protected:
    
    Vertices MeshVertices; 

    unsigned int _VAO, _VBO, _EBO, _TEX;
    unsigned int _shaderId;

    std::vector<std::unique_ptr<Texture>> _textures;
    glm::mat4 _transform;

    void SetupTexture();
    void ActiveAndBindTexture();
    void ProcessTransform();

    friend class MeshBuilder;
};


#endif