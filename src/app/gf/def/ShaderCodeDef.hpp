#ifndef SHADERCODEDEF_HPP
#define SHADERCODEDEF_HPP

#include <string>

namespace ShaderCodeDef
{
const std::string vertexshadercode01 = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 3) in vec4 aCol;

        out vec4 Color;

        uniform mat4 transform;

        void main()
        {
            gl_Position = transform * vec4(aPos, 1.0f);
            Color = aCol;
        }
    )";

const std::string fragmentshadercode01 = R"(
        #version 330 core
        out vec4 FragColor;

        in vec4 Color;

        void main()
        {
            FragColor = Color;
        }
    )";
}; // namespace ShaderCodeDef

#endif