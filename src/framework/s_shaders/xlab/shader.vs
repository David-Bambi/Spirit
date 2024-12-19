#version 330 core

layout (location = 0) in vec3 vertices;
layout (location = 1) in vec2 texture_coord;
layout (location = 2) in vec3 normal_coord;

out vec2 CoordTexture;

uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;

void main()
{
gl_Position = projection * view * model * vec4(vertices, 1.0);
CoordTexture = texture_coord;
}
