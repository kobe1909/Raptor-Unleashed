#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform vec4 cameraPosition;
uniform vec4 cameraRotation;
uniform vec4 displaySurfacePosition;

out vec4 vertexColor;

void main() {
    vec2 projection;
    vec3 d;
    
    float x = position.x - cameraPosition.x;
    float y = position.y - cameraPosition.y;
    float z = position.z - cameraPosition.z;
    
    d.x = cameraPosition.y * (sin(cameraRotation.z) * y + cos(cameraRotation.z) * x) - sin(cameraRotation.y) * z;
    d.y = sin(cameraRotation.x) * (cos(cameraRotation.y) * z + sin(cameraRotation.y) * (sin(cameraRotation.z) * y + cos(cameraRotation.z) * x)) + cos(cameraRotation.x) * (cameraRotation.z * y - sin(cameraRotation.z) * x);
    d.z = cos(cameraRotation.x) * (cos(cameraRotation.y) * z * sin(cameraRotation.y) * (sin(cameraRotation.z) * y + cos(cameraRotation.z) * x)) - sin(cameraRotation.x) * (cameraRotation.z * y - sin(cameraRotation.z) * x);
    
    projection.x = ((displaySurfacePosition.z) / d.z) * d.x + displaySurfacePosition.x;
    projection.y = ((displaySurfacePosition.z) / d.x) * d.y + displaySurfacePosition.y;
    
    gl_Position = vec4(projection.xy, 1, 1);
    vertexColor = color;
}


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec4 vertexColor;

void main() {
	color = vertexColor;
};