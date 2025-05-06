#include <shader/Shader.hpp>

void Shader::Compile()
{
    const unsigned int vertex = ShaderProg::Compile(vertexCode, GL_VERTEX_SHADER);
    const unsigned int fragment = ShaderProg::Compile(fragmentCode, GL_FRAGMENT_SHADER); 

    const char* shaderCodetocompile = shaderCode.c_str();

    // 2. compile shaders
    unsigned int shader = 0;
    int success = 0;
    std::array<char, 512> infoLog = {};

    shader = glCreateShader(typeShader);
    glShaderSource(shader, 1, &shaderCodetocompile, nullptr);
    glCompileShader(shader);

    // print compile errors if any
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog.data());
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog.data() << '\n';
    };

}
