#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 2) in vec2 aTex;
layout (location = 3) in vec4 aCol;

out vec2 TexCoord;
out vec4 Color;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    TexCoord = aTex;
    Color = aCol;
}