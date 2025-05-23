#ifndef PROGAMSHADERDEF_HPP
#define PROGAMSHADERDEF_HPP

#include <shader/ProgramShader.hpp>
#include <shader/ProgramShaderBuilder.hpp>
#include <def/ShaderDef.hpp>

namespace ProgramShaderDef
{
const std::shared_ptr<ProgramShader> Program01 =
    ProgramShaderBuilder::GetInstance()
        .WithVertexShader(ShaderDef::VertexShader01)
        .WithFragmentShader(ShaderDef::FragmentShader01)
        .BuildShared();

const std::shared_ptr<ProgramShader> Program02 =
        ProgramShaderBuilder::GetInstance()
            .WithVertexShader(ShaderDef::VertexShader02)
            .WithFragmentShader(ShaderDef::FragmentShader02)
            .BuildShared();
}

#endif