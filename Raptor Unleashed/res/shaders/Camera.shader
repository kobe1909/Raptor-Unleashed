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

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

layout(location = 0) out vec4 color;

uniform vec3 cameraPos;

uniform Material material;
uniform Light light;

in vec3 normal;
in vec3 FragPos;

void main() {
    // ambient
    vec3 ambient = light.ambient * material.ambient;
    
    // diffuse
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * (diff * material.diffuse);
    
    // specular
    vec3 viewDir = normalize(cameraPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * material.specular);
    
    vec3 result = ambient + diffuse + specular;
    color = vec4(result, 1.0);
};