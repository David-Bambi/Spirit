#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 3) in vec4 aCol;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

out vec4 Color;

void main()
{   gl_Position =  projection * view * transform * vec4(aPos, 1.0);
    Color = aCol;
}
