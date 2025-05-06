#include <shader/ShaderBuilder.hpp>

#include <file/ReadFile.hpp>

ShaderBuilder& ShaderBuilder::GetInstance()
{
    static ShaderBuilder instance;
    return instance;
}

ShaderBuilder& ShaderBuilder::WithCode(const std::string& ShaderCode)
{
    _obj->_shaderCode = ShaderCode;
    return *this;
}

ShaderBuilder& ShaderBuilder::WithCode(const Path& ShaderPath)
{
    _obj->_shaderCode = ReadFile(ShaderPath.PathCstr());
    return *this;
}

ShaderBuilder& ShaderBuilder::WithType(ShaderType type)
{
    _obj->_type = type;
    return *this;
}

std::unique_ptr<Shader> ShaderBuilder::Build()
{
    Builder::_obj->Create();
    Builder::_obj->Compile();

    return Builder::Build();
}

