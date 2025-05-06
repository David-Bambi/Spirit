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

    ProgramShaderBuilder& WithVertexShader(std::unique_ptr<Shader> vertexShader);
    ProgramShaderBuilder& WithFragmentShader(std::unique_ptr<Shader> fragmentShader);

    std::unique_ptr<ProgramShader> Build();
};

#endif