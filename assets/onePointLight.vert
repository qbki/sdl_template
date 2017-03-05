#version 430

layout (location=0) in vec3 VertexPosition;
layout (location=1) in vec3 VertexNormal;

out vec3 Color;

/*uniform vec4 LightPosition;*/
vec3 LightPosition = vec3(0.0, 10.0, 0.0);
/*vec3 LightVector = vec3(0.0, -1.0, 0.0);*/
/*vec3 LightDirection = vec3(0.0, 1.0, 0.0);*/
vec3 ObjectColor = vec3(1.0, 0.0, 0.0);

uniform mat4 VM;
uniform mat4 PVM;
uniform mat3 NM;

void main() {
    vec3 tnorm = normalize(NM * VertexNormal);
    vec4 eye = VM * vec4(VertexPosition, 1.0);
    vec3 s = normalize(vec3(LightPosition - vec3(eye)));
    Color = ObjectColor * max(dot(s, tnorm), 0.0);

    /*Color = ObjectColor * max(dot(VertexNormal, LightVector), 0.0);*/

    /*Color = ObjectColor * max(dot(normalize(LightPosition - VertexPosition), VertexNormal), 0.0);*/

    gl_Position = PVM * vec4(VertexPosition, 1.0);
}