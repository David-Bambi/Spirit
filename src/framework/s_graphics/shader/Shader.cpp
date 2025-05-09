#include <shader/Shader.hpp>

#include <glad/glad.h>
#include <array>
#include <iostream>

void Shader::Compile()
{
    _id = glCreateShader(_type);

    const char* shaderCodetocompile = _shaderCode.c_str();

    glShaderSource(_id, 1, &shaderCodetocompile, nullptr);
    glCompileShader(_id);
    LogCompileError();
}

void Shader::LogCompileError()
{
    int success = 0;
    glGetShaderiv(_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        std::array<char, 512> infoLog = {};
        glGetShaderInfoLog(_id, 512, nullptr, infoLog.data());
        std::cout << "ERROR::SHADER::" << _type << "::COMPILATION_FAILED" << "\n"
                  << infoLog.data() << '\n';
    };
}

unsigned int Shader::Id() const
{
    return _id;
}