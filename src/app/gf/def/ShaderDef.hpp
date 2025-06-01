#ifndef SHADERDEF_HPP
#define SHADERDEF_HPP

#include <shader/Shader.hpp>
#include <shader/ShaderBuilder.hpp>
#include <def/ShaderCodeDef.hpp>
#include <memory>

namespace ShaderDef
{
const std::shared_ptr<Shader> VertexShader01 = ShaderBuilder::GetInstance()
                                                   .WithCode(ShaderCodeDef::vertexshadercode01)
                                                   .WithType(ShaderType::VERTEX_SHADER)
                                                   .BuildShared();

const std::shared_ptr<Shader> FragmentShader01 = ShaderBuilder::GetInstance()
                                                     .WithCode(ShaderCodeDef::fragmentshadercode01)
                                                     .WithType(ShaderType::FRAGMENT_SHADER)
                                                     .BuildShared();

const std::shared_ptr<Shader> VertexShader02 = ShaderBuilder::GetInstance()
                                                   .WithCode(ShaderCodeDef::vertexshadercode02)
                                                   .WithType(ShaderType::VERTEX_SHADER)
                                                   .BuildShared();

const std::shared_ptr<Shader> FragmentShader02 = ShaderBuilder::GetInstance()
                                                     .WithCode(ShaderCodeDef::fragmentshadercode02)
                                                     .WithType(ShaderType::FRAGMENT_SHADER)
                                                     .BuildShared();
}; // namespace ShaderDef

#endif