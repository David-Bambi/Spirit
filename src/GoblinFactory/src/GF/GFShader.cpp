#include <GF/GFShader.hpp>

GFShader::GFShader(const char* vertexPath,
                   const char* fragmentPath)
{
  std::string vertexCode = this->ReadShaderCode(vertexPath);
  std::string fragmentCode = this->ReadShaderCode(fragmentPath);

  unsigned int vertex = GFShader::Compile(vertexCode,
                                          GL_VERTEX_SHADER);
  
  unsigned int fragment = GFShader::Compile(fragmentCode,
                                            GL_FRAGMENT_SHADER);
  int success;
  char infoLog[512];
  
  // shader Program
  this->_id = glCreateProgram();
  glAttachShader(this->_id, vertex);
  glAttachShader(this->_id, fragment);
  glLinkProgram(this->_id);
  // print linking errors if any
  glGetProgramiv(this->_id, GL_LINK_STATUS, &success);
  if(!success)
    {
      glGetProgramInfoLog(this->_id, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
  
  // delete the shaders as they're linked into our program now and no longer necessary
  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

unsigned int GFShader::Id()
{
  return this->_id;
}

void GFShader::Id(unsigned int id)
{
  this->_id = id;
}

// use/activate the shader
void GFShader::Use()
{
  glUseProgram(this->_id);
}

// utility uniform functions
void GFShader::SetBool(const std::string &name, bool value) const
{
  glUniform1i(glGetUniformLocation(_id, name.c_str()), (int)value); 
}
void GFShader::SetInt(const std::string &name, int value) const
{
  glUniform1i(glGetUniformLocation(_id, name.c_str()), value); 
}
void GFShader::SetFloat(const std::string &name, float value) const
{
  glUniform1f(glGetUniformLocation(_id, name.c_str()), value); 
}

void GFShader::SetMat4(const char* name, const glm::mat4 &mat) const
{
  glUniformMatrix4fv(glGetUniformLocation(_id, name), 1, GL_FALSE, &mat[0][0]);
}



unsigned int GFShader::Compile(std::string shaderCode,
                               unsigned int typeShader)
{
  const char* shaderCodetocompile = shaderCode.c_str();
  
  // 2. compile shaders
  unsigned int shader;
  int success;
  char infoLog[512];
   
  shader = glCreateShader(typeShader);
  glShaderSource(shader, 1, &shaderCodetocompile, NULL);
  glCompileShader(shader);
  
  // print compile errors if any
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if(!success)
    {
      glGetShaderInfoLog(shader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

  return shader;
}


std::string GFShader::ReadShaderCode(const char* filePath)
{
  std::string shaderCode;
  std::ifstream shaderFile;
  // ensure ifstream objects can throw exceptions:
  shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

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
  catch(std::ifstream::failure e)
    {
      std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
  return shaderCode;
}
