#include <ugl/ugl.hpp>

#include <stdexcept>

/**
 * @brief Check if the size is less than or equal to the maximum value of GLsizei
 *        and return the size as GLsizei. If the size is greater than the maximum value of GLsizei,
 * throw an exception. This is useful to prevent overflow when passing size to OpenGL functions.
 */
GLint UGL::SafeGlint(unsigned long num)
{
    if (num > std::numeric_limits<GLint>::max())
    {
        throw std::runtime_error("Num(unsigned long) exceeds GLint limit");
    }
    return static_cast<GLint>(num);
}
GLint UGL::SafeGlint(unsigned int num)
{
    if (num > std::numeric_limits<GLint>::max())
    {
        throw std::runtime_error("Num(unsigned int) exceeds GLint limit");
    }
    return static_cast<GLint>(num);
}
GLsizei UGL::SafeGlsizei(std::size_t size)
{
    if (size > std::numeric_limits<GLsizei>::max())
    {
        throw std::runtime_error("Size(std::size_t) exceeds GLsizei limit");
    }
    return static_cast<GLsizei>(size);
}

GLsizei UGL::SafeGlsizei(unsigned int size)
{
    if (size > std::numeric_limits<GLsizei>::max())
    {
        throw std::runtime_error("Size(unsigned int) exceeds GLsizei limit");
    }
    return static_cast<GLsizei>(size);
}

GLsizeiptr UGL::SafeGlsizeiptr(unsigned long size)
{
    if (size > std::numeric_limits<GLsizeiptr>::max())
    {
        throw std::runtime_error("Size(unsigned long) exceeds GLsizeiptr limit");
    }
    return static_cast<GLsizeiptr>(size);
}