#include <shader/ShaderProg.hpp>
#include <array>

ShaderProg::ShaderProg(const char* vertexPath, const char* fragmentPath) : _id(glCreateProgram())
{
    const std::string vertexCode = this->ReadShaderCode(vertexPath);
    const std::string fragmentCode = this->ReadShaderCode(fragmentPath);

    const unsigned int vertex = ShaderProg::Compile(vertexCode, GL_VERTEX_SHADER);

    const unsigned int fragment = ShaderProg::Compile(fragmentCode, GL_FRAGMENT_SHADER);
    int success = 0;
    std::array<char, 512> infoLog = {};

    glAttachShader(this->_id, vertex);
    glAttachShader(this->_id, fragment);
    glLinkProgram(this->_id);

    glGetProgramiv(this->_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(this->_id, 512, nullptr, infoLog.data());
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog.data() << "\n";
        std::cout << vertexCode << "\n";
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

ShaderProg::~ShaderProg()
{
    glDeleteProgram(this->_id);
}

unsigned int ShaderProg::Id()
{
    return this->_id;
}

void ShaderProg::Id(unsigned int id)
{
    this->_id = id;
}

// use/activate the shader
void ShaderProg::Use()
{
    glUseProgram(this->_id);
}

// utility uniform functions
void ShaderProg::SetBool(const std::string& name, bool value) const
{
    glUniform1i(glGetUniformLocation(_id, name.c_str()), (int) value);
}
void ShaderProg::SetInt(const std::string& name, int value) const
{
    glUniform1i(glGetUniformLocation(_id, name.c_str()), value);
}
void ShaderProg::SetFloat(const std::string& name, float value) const
{
    glUniform1f(glGetUniformLocation(_id, name.c_str()), value);
}
void ShaderProg::SetMat4(const char* name, const glm::mat4& mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(_id, name), 1, GL_FALSE, &mat[0][0]);
}

unsigned int ShaderProg::Compile(const std::string& shaderCode, unsigned int typeShader)
{
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

    return shader;
}

std::string ShaderProg::ReadShaderCode(const char* filePath)
{
    std::string shaderCode;
    std::ifstream shaderFile;
    // ensure ifstream objects can throw exceptions:
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // open files
        shaderFile.open(filePath);
        std::stringstream shaderStream;
        // read file's buffer contents into streams
        shaderStream << shaderFile.rdbuf();
        // close file handlers
        shaderFile.close();
        // convert stream into string
        shaderCode = shaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ\n";
    }
    return shaderCode;
}
