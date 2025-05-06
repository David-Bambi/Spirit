#include <shader/ShaderBuilder.hpp>

ShaderBuilder& ShaderBuilder::WithVertexShader(const std::string& vertexShader)
{
    _obj->_vertexShader = vertexShader;
    return *this;
}

ShaderBuilder& ShaderBuilder::WithFragmentShader(const std::string& fragmentShader)
{
    _obj->_fragmentShader = fragmentShader;
    return *this;
}

ShaderBuilder& ShaderBuilder::WithGeometryShader(const std::string& geometryShader)
{
    _obj->_geometryShader = geometryShader;
    return *this;
}
