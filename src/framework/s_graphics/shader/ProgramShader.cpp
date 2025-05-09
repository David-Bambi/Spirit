
#include <glad/glad.h>
#include <shader/ProgramShader.hpp>
#include <iostream>
#include <array>

void ProgramShader::Init()
{
    _vertexShader->Compile();
    _fragmentShader->Compile();

    GenerateId();
    Link();
}

void ProgramShader::GenerateId()
{
    _id = glCreateProgram();
}

void ProgramShader::Link() const
{
    glAttachShader(this->_id, _vertexShader->Id());
    glAttachShader(this->_id, _fragmentShader->Id());
    glLinkProgram(this->_id);
    LogLinkError();

    glDeleteShader(_vertexShader->Id());
    glDeleteShader(_fragmentShader->Id());
}

void ProgramShader::Use() const
{
    glUseProgram(_id);
}

unsigned int ProgramShader::Id() const
{
    return _id;
}

void ProgramShader::LogLinkError() const
{
    int success = 0;
    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        std::array<char, 512> infoLog = {};
        glGetProgramInfoLog(_id, 512, nullptr, infoLog.data());
        std::cout << "ERROR::SHADER::ProgramShader::LINKING_FAILED\n" << infoLog.data() << "\n";
    }
}
