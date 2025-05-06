#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <object/Object.hpp>
#include <string/StrDef.hpp>

class Shader : public Object
{
  public:
    unsigned int Id() const { return _id; }

  private:
    unsigned int _id = -1;

    const std::string& _vertexShaderPath = STREMPTY;
    const std::string& _fragmentShaderPath = STREMPTY;
    const std::string& _geometryShaderPath = STREMPTY;

    const std::string& _vertexShaderCode = STREMPTY;
    const std::string& _fragmentShaderCode = STREMPTY;
    const std::string& _geometryShaderCode = STREMPTY;

    void Compile();
    void Link();
    void Use();
    
    friend class ShaderBuilder;
};

#endif