#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
uniform sampler2D tex1;

void main()
{
    FragColor = texture(tex1, TexCoord);
} 