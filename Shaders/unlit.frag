#version 330 core

out vec4 FragColor;
uniform vec4 ParticleColor;

void main()
{
    //FragColor = vec4(0.5f, 0.0f, 0.0f, 1.0f);
    FragColor = ParticleColor;
}