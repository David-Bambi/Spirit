#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include <vector>
#include <glad/glad.h>

class Renderable
{
public :

    GLenum DrawUsage = GL_STATIC_DRAW;
    bool IsInstancied = false;

    virtual const int InstanceId()=0;
    virtual const std::vector<float> Vertex()=0;
    virtual void Render()=0;
};

#endif 