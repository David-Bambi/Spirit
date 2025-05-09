#ifndef SHADERBUILDER_HPP
#define SHADERBUILDER_HPP

#include <builder/Builder.hpp>
#include <file/Path.hpp>
#include <memory>
#include <shader/Shader.hpp>
#include <shader/ShaderType.hpp>

class ShaderBuilder : public Builder<Shader>
{
  public:
    static ShaderBuilder& GetInstance();

    ShaderBuilder& WithCode(const Path& ShaderPath);
    ShaderBuilder& WithCode(const std::string& ShaderCode);
    ShaderBuilder& WithType(ShaderType type);
};

#endif