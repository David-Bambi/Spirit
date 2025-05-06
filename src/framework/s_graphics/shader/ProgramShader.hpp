#ifndef PROGRAMSHADER_HPP
#define PROGRAMSHADER_HPP

#include <glad/glad.h>
#include <object/Object.hpp>
#include <memory>
#include <shader/Shader.hpp> 

class ProgramShader : public Object
{
    public :
        void Use() const;
    private :
        unsigned int _id = -1;
        std::unique_ptr<Shader> _vertexShader = {};
        std::unique_ptr<Shader> _fragmentShader = {};

        void Create();
        void Link() const;
        void LogLinkError() const;

        friend class ProgramShaderBuilder;
};

#endif 