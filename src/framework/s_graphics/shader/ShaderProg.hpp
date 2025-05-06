#ifndef SHADER_PROG_HPP
#define SHADER_PROG_HPP

#include <fstream>
#include <glad/glad.h>
#include <iostream>
#include <sstream>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProg
{
  private:
    unsigned int _id;

    std::string ReadShaderCode(const char* filePath);
    unsigned int Compile(const std::string& shaderCode, unsigned int shaderType);

  public:
    // Constructor
    ShaderProg(const char* vertexPath, const char* fragmentPath);
    ~ShaderProg();
    ShaderProg(const ShaderProg&) = default;
    ShaderProg(ShaderProg&&) = default;
    ShaderProg& operator=(const ShaderProg&) = default;
    ShaderProg& operator=(ShaderProg&&) = default;

    // Getter and Setter
    unsigned int Id();
    void Id(unsigned int id);

    // Activate the shader
    void Use();

    // Utility uniform functions
    void SetBool(const std::string& name, bool value) const;
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetMat4(const char* name, const glm::mat4& mat) const;
};

#endif
