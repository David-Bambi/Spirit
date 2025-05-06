#ifndef SHADERBUILDER_HPP
#define SHADERBUILDER_HPP

#include <shader/Shader.hpp>

class ShaderBuilder
{
  public:
    static ShaderBuilder& GetInstance();

    ShaderBuilder& WithVertexShader(const std::string& vertexShader);
    ShaderBuilder& WithFragmentShader(const std::string& fragmentShader);
    ShaderBuilder& WithGeometryShader(const std::string& geometryShader);

    ShaderBuilder& WithVertexShader(const std::string& vertexShader);
    ShaderBuilder& WithFragmentShader(const std::string& fragmentShader);
    ShaderBuilder& WithGeometryShader(const std::string& geometryShader);
};

#endif