#ifndef PROGRAMSHADER_HPP
#define PROGRAMSHADER_HPP

#include <glad/glad.h>
#include <object/Object.hpp>
#include <memory>
#include <shader/Shader.hpp>

class ProgramShader : public Object
{
  public:
    void Init();
    void Use() const;
    [[nodiscard]] unsigned int Id() const;

  private:
    unsigned int _id = -1;
    std::shared_ptr<Shader> _vertexShader = {};
    std::shared_ptr<Shader> _fragmentShader = {};

    void GenerateId();
    void Link() const;
    void LogLinkError() const;

    friend class ProgramShaderBuilder;
};

#endif