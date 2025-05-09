#include <mesh/Mesh.hpp>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include <texture/GLTexture.hpp>
#include <ugl/ugl.hpp>

void Mesh::Clean()
{
    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
    glDeleteBuffers(1, &_ebo);
}

void Mesh::Render()
{
    glUseProgram(_shaderId);

    ProcessTransform();

    ActiveAndBindTexture();

    glBindVertexArray(_vao);

    if (MeshVertices.Indexs().size() > 0)
        glDrawElements(GL_TRIANGLES, UGL::SafeGlsizei(MeshVertices.Indexs().size()),
                       GL_UNSIGNED_INT, nullptr);
    else
        glDrawArrays(GL_TRIANGLES, 0, UGL::SafeGlsizei(MeshVertices.Count()));

    glBindVertexArray(0);
}

void Mesh::Init(unsigned int progshader)
{
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);
    _shaderId = progshader;

    MeshVertices.Build();

    glUseProgram(_shaderId);
    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 UGL::SafeGlsizeiptr(MeshVertices.VerticesVec().size() * sizeof(float)),
                 MeshVertices.VerticesVec().data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 UGL::SafeGlsizeiptr(MeshVertices.Indexs().size() * sizeof(unsigned int)),
                 MeshVertices.Indexs().data(), GL_STATIC_DRAW);

    MeshVertices.SetVertexAttrPtr();

    SetupTexture();

    glBindVertexArray(0);
}

void Mesh::SetupTexture()
{
    for (long unsigned int i = 0; i < _textures.size(); i++)
    {
        const std::string texname = "tex" + std::to_string(i);
        glUniform1i(glGetUniformLocation(_shaderId, texname.c_str()), UGL::SafeGlint(i));

        _textures[i]->GenerateTexture();
    }
}

void Mesh::ActiveAndBindTexture()
{
    for (long unsigned int i = 0; i < _textures.size(); i++)
    {
        glActiveTexture(GLTexture::gltex[i]);
        glBindTexture(GL_TEXTURE_2D, _textures[i]->Id());
    }
}

void Mesh::Transform(glm::mat4 transform)
{
    _transform = transform;
}

void Mesh::ProcessTransform()
{
    const unsigned int transformLoc = glGetUniformLocation(_shaderId, "transform");
    glUniformMatrix4fv(UGL::SafeGlint(transformLoc), 1, GL_FALSE, glm::value_ptr(_transform));
}
