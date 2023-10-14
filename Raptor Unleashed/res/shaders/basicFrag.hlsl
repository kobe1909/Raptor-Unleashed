#version 330 core

in vec4 fragmentColor;

layout(location = 1) out vec4 color;

void main() {
    color = fragmentColor;
};