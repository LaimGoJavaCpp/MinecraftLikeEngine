#version 330
in vec3 position;
in vec3 color;

uniform mat4 modelMatrix;

out vec3 pass_color;

void main() {
    gl_Position = modelMatrix * vec4(position, 1.0);
    pass_color = color;
}