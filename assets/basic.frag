#version 430

out vec4 FragColor;

uniform vec3 Color;

void main () {
    FragColor = vec4(Color, 1.0);
}
