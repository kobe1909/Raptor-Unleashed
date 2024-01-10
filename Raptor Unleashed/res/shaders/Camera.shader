#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 inNormal;


uniform mat4 Model;
uniform mat4 View;
uniform mat4 Proj;

out vec3 normal;
out vec3 FragPos;

void main() {    
    FragPos = vec3(Model * vec4(position, 1.0));
    normal = mat3(transpose(inverse(Model))) * inNormal;
    gl_Position = Proj * View * vec4(FragPos, 1.0);
}



#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec3 LightColor;
uniform vec3 lightPos;
uniform vec3 objectColor;
uniform vec3 cameraPos;

in vec3 normal;
in vec3 FragPos;

void main() {
    // ambient
    float ambientStrength = 0.5;
    vec3 ambient = ambientStrength * LightColor;
    
    // diffuse
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * LightColor;
    
    // specular
    float specularStrength = 0.5;
    float shininess = 32;
    vec3 viewDir = normalize(cameraPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    vec3 specular = specularStrength * spec * LightColor;
    
    vec3 result = (ambient + diffuse + specular) * objectColor;
    color = vec4(result, 1.0);
};