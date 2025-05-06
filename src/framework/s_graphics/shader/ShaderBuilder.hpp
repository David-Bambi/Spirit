#ifndef SHADERBUILDER_HPP
#define SHADERBUILDER_HPP

#include <shader/Shader.hpp>
#include <file/Path.hpp>
#include <shader/ShaderType.hpp>
#include <builder/Builder.hpp>

class ShaderBuilder : public Builder<Shader>
{
  public:
    static ShaderBuilder& GetInstance();

    ShaderBuilder& WithCode(const Path& ShaderPath);
    ShaderBuilder& WithCode(const std::string& ShaderCode);
    ShaderBuilder& WithType(ShaderType type);

    std::unique_ptr<Shader> Build();
};

#endif