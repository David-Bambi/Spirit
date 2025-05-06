#ifndef UGL_H
#define UGL_H

#include <glad/glad.h>

#include <limits>

namespace UGL
{
GLint SafeGlint(unsigned long num);
GLint SafeGlint(unsigned int num);
GLsizei SafeGlsizei(std::size_t size);
GLsizei SafeGlsizei(unsigned int size);
GLsizeiptr SafeGlsizeiptr(unsigned long size);
} // namespace UGL

#endif