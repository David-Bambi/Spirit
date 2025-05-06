#include <shader/ProgramShaderBuilder.hpp>

ProgramShaderBuilder& ProgramShaderBuilder::GetInstance()
{
    static ProgramShaderBuilder instance;
    return instance;
}

ProgramShaderBuilder& ProgramShaderBuilder::WithVertexShader(std::unique_ptr<Shader> vertexShader)
{
    _obj->_vertexShader = std::move(vertexShader);
    return *this;   
}

ProgramShaderBuilder& ProgramShaderBuilder::WithFragmentShader(std::unique_ptr<Shader> fragmentShader)
{
    _obj->_fragmentShader = std::move(fragmentShader);
    return *this;
}

std::unique_ptr<ProgramShader> ProgramShaderBuilder::Build()
{
    Builder::_obj->Create();
    Builder::_obj->Link();
    
    return Builder::Build();
}