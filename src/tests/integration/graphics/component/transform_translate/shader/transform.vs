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