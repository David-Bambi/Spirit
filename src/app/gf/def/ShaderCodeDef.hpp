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

        uniform mat4 view;
        uniform mat4 projection;
        uniform mat4 transform;

        void main()
        {
            gl_Position =  projection * view * transform * vec4(aPos, 1.0);
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

    const std::string vertexshadercode02 = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;

        uniform mat4 view;
        uniform mat4 projection;
        uniform mat4 transform;

        void main()
        {
            gl_Position =  projection * view * transform * vec4(aPos, 1.0);
        }
    )";

const std::string fragmentshadercode02 = R"(
        #version 330 core
        out vec4 FragColor;

        void main()
        {
            FragColor = vec4(255.0, 0.0, 0.0f, 1.0);
        }
    )";
}; // namespace ShaderCodeDef

#endif