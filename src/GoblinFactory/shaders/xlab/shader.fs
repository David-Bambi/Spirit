#version 330 core

out vec4 Frag;

in vec2 CoordTexture;

uniform sampler2D texture;

void main()
{
    Frag = texture(texture, CoordTexture) * vec4(1.0,1.0,1.0,1.0);
}