#ifndef PROGRAMSHADERBUILDER_HPP
#define PROGRAMSHADERBUILDER_HPP

#include <shader/Shader.hpp>
#include <shader/ProgramShader.hpp>
#include <builder/Builder.hpp>
#include <memory>

class ProgramShaderBuilder : public Builder<ProgramShader>
{
  public:
    static ProgramShaderBuilder& GetInstance();

    ProgramShaderBuilder& WithVertexShader(const std::shared_ptr<Shader>& vertexShader);
    ProgramShaderBuilder& WithFragmentShader(const std::shared_ptr<Shader>& fragmentShader);
};

#endif