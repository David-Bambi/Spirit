
#include <model/Vertices.hpp>

#include <color/Color_t.hpp>
#include <glad/glad.h>
#include <iostream>
/**
 * @brief Set the position vertices for the mesh
 *
 * @param position : vector of normilized position
 */
void Vertices::SetPosition(const std::vector<glm::vec3>& position)
{
    _vertextype.set(0);
    _pos = position;
    _count = position.size();
}

/**
 * @brief Set the color for each vertex for the mesh
 *
 * @param color : vector of color. It must be the same size as the position
 */
void Vertices::SetColor(std::vector<Color_t> color)
{
    _vertextype.set(3);
    _col = std::move(color);
}

/**
 * @brief Set the texture coordinate for each certex of the mesh
 *
 * @param TexCoord
 */
void Vertices::SetTexture(const std::vector<glm::vec2>& TexCoord)
{
    _vertextype.set(2);
    _tex = TexCoord;
}

const std::vector<float> Vertices::VerticesVec()
{
    return _vertices_vec;
}

const std::vector<unsigned int> Vertices::Indexs()
{
    return _indexs;
}

void Vertices::SetIndexs(const std::vector<unsigned int>& Indexs)
{
    _indexs = Indexs;
}

unsigned int Vertices::Count()
{
    return _count;
}

/**
 * @brief Build the vertice vector to send on VBO
 *
 */
void Vertices::Build()
{
    for (long unsigned int i = 0; i < _pos.size(); i++)
    {
        _vertices_vec.push_back(_pos[i].x);
        _vertices_vec.push_back(_pos[i].y);
        _vertices_vec.push_back(_pos[i].z);

        if (_vertextype.test(2))
        {
            _vertices_vec.push_back(_tex[i].x);
            _vertices_vec.push_back(_tex[i].y);
        }

        if (_vertextype.test(3))
        {
            _vertices_vec.push_back(_col[i].red);
            _vertices_vec.push_back(_col[i].green);
            _vertices_vec.push_back(_col[i].blue);
            _vertices_vec.push_back(_col[i].opacity);
        }
    }
    InitVertexInfo();
}

/**
 * @brief Set the vertex attribute pointer for the shader
 *
 */
void Vertices::SetVertexAttrPtr()
{
    if (_vertextype.test(0))
    {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _stride, (void*) _offset.pos); // NOLINT
        glEnableVertexAttribArray(0);
    }
    if (_vertextype.test(2))
    {
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, _stride, (void*) _offset.tex); // NOLINT
        glEnableVertexAttribArray(2);
    }
    if (_vertextype.test(3))
    {
        glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, _stride, (void*) _offset.col); // NOLINT
        glEnableVertexAttribArray(3);
    }
}

/**
 * @brief Initialise the stride and the offset for setting attribute pointer.
 *
 */
void Vertices::InitVertexInfo()
{
    // Position
    if (_vertextype == 0b0001)
    {
        _stride = sizeof(VertexPos);
        _offset.pos = offsetof(VertexPos, position);
    }

    // Position, texture
    if (_vertextype == 0b0101)
    {
        _stride = sizeof(VertexPosTex);
        _offset.pos = offsetof(VertexPosTex, position);
        _offset.tex = offsetof(VertexPosTex, texture);
    }

    // Position, Color
    if (_vertextype == 0b1001)
    {
        _stride = sizeof(VertexPosCol);
        _offset.pos = offsetof(VertexPosCol, position);
        _offset.col = offsetof(VertexPosCol, color);
    }

    // Position, texture, color
    if (_vertextype == 0b1101)
    {
        _stride = sizeof(VertexPosTexCol);
        _offset.pos = offsetof(VertexPosTexCol, position);
        _offset.tex = offsetof(VertexPosTexCol, texture);
        _offset.col = offsetof(VertexPosTexCol, color);
    }
}