#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <object/Object.hpp>
#include <string/StrDef.hpp>
#include <string>
#include <shader/ShaderType.hpp>

class Shader : public Object
{
  public:
    [[nodiscard]] unsigned int Id() const;

    void Compile();

  private:
    unsigned int _id = -1;
    ShaderType _type = ShaderType::VERTEX_SHADER;
    std::string _shaderCode = STREMPTY;

    void LogCompileError();

    friend class ShaderBuilder;
};

#endif