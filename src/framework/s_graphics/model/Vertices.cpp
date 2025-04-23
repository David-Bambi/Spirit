
#include <model/Vertices.hpp>

#include <color/Color_t.hpp>
#include <glad/glad.h>
#include <iostream>
/**
 * @brief Set the position vertices for the mesh
 * 
 * @param position : vector of normilized position
 */
void Vertices::SetPosition(std::vector<glm::vec3> position)
{
    _vertextype.set(0);
    _pos = position;
    Count = position.size();
}

/**
 * @brief Set the color for each vertex for the mesh
 * 
 * @param color : vector of color. It must be the same size as the position
 */
void Vertices::SetColor(std::vector<Color_t> color)
{
    _vertextype.set(3);
    _col = color;
}

/**
 * @brief Set the texture coordinate for each certex of the mesh
 * 
 * @param TexCoord 
 */
void Vertices::SetTexture(const std::vector<glm::vec2> TexCoord)
{
    _vertextype.set(2);
    _tex = TexCoord;
}

/**
 * @brief Build the vertice vector to send on VBO
 * 
 */
void Vertices::Build()
{
    for (int i = 0; i<_pos.size() ; i++)
    {
        Vertices.push_back(_pos[i].x);
        Vertices.push_back(_pos[i].y);
        Vertices.push_back(_pos[i].z);

        if (_vertextype.test(2))
        {
            Vertices.push_back(_tex[i].x);
            Vertices.push_back(_tex[i].y);
        }

        if (_vertextype.test(3))
        {
            Vertices.push_back(_col[i].red);
            Vertices.push_back(_col[i].green);
            Vertices.push_back(_col[i].blue);
            Vertices.push_back(_col[i].opacity);
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
        glVertexAttribPointer(0,  
                              3,
                              GL_FLOAT,
                              GL_FALSE,
                              _stride,
                              (void*)_offset.pos);
        glEnableVertexAttribArray(0); 
    }
    if (_vertextype.test(2))
    {
        glVertexAttribPointer(2,  
                              2,
                              GL_FLOAT,
                              GL_FALSE,
                              _stride,
                              (void*)_offset.tex);
        glEnableVertexAttribArray(2); 
    }
    if (_vertextype.test(3))
    {
        glVertexAttribPointer(3,  
                              4,
                              GL_FLOAT,
                              GL_FALSE,
                              _stride,
                              (void*)_offset.col);
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