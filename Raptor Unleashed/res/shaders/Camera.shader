#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 inNormal;


uniform mat4 Model;
uniform mat4 View;
uniform mat4 Proj;

out vec3 normal;
out vec3 FragPos;

void main() {    
    gl_Position = Proj * View * Model * position;
    normal = mat3(transpose(inverse(Model))) * inNormal;
    FragPos = vec3(Model * vec4(position.xyz, 1.0));;
}



#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec3 LightColor;
uniform vec3 lightPos;
uniform vec3 objectColor;

in vec3 normal;
in vec3 FragPos;

void main() {
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * LightColor;
    
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * LightColor;
    
    vec3 result = (ambient + diffuse) * objectColor;
    color = vec4(result, 1.0);
};