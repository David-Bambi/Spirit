#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 3) in vec4 aCol;

out vec4 Color;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    Color = aCol;
}
