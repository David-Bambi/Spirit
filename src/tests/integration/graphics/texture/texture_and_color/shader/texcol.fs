#version 330 core
out vec4 FragColor;

in vec4 Color;
in vec2 TexCoord;
uniform sampler2D tex1;
uniform sampler2D tex2;
uniform sampler2D tex3;


void main()
{
    vec4 FirstMix = mix(texture(tex1, TexCoord), texture(tex2, TexCoord), 0.5);
    FragColor =  mix(FirstMix, texture(tex3, TexCoord), 0.5) * Color; 
} 