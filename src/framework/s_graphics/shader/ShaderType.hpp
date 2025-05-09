#ifndef GLSHADER_HPP
#define GLSHADER_HPP

#include <cstdint>

enum ShaderType : std::uint16_t
{
    VERTEX_SHADER = GL_VERTEX_SHADER,
    FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
};

#endif