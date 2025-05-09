#include <shader/ProgramShaderBuilder.hpp>

ProgramShaderBuilder& ProgramShaderBuilder::GetInstance()
{
    static ProgramShaderBuilder instance;
    return instance;
}

ProgramShaderBuilder&
ProgramShaderBuilder::WithVertexShader(const std::shared_ptr<Shader>& vertexShader)
{
    _obj->_vertexShader = vertexShader;
    return *this;
}

ProgramShaderBuilder&
ProgramShaderBuilder::WithFragmentShader(const std::shared_ptr<Shader>& fragmentShader)
{
    _obj->_fragmentShader = fragmentShader;
    return *this;
}
