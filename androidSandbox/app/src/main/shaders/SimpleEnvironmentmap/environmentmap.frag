#version 450

layout(set = 0, binding = 0) uniform UniformCustomBufferObject { 
    vec3 cameraPos;
} customUBO;

layout(set = 1, binding = 0) uniform samplerCube cubemapSampler;

//layout(location = 0) in vec3 fragColor;
//layout(location = 1) in vec2 fragTexCoord;
layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;

layout(location = 0) out vec4 outColor;

void main() {
    vec3 I = normalize(pos - customUBO.cameraPos);
    vec3 R = reflect(I, normalize(normal));
    outColor = texture(cubemapSampler, R);
}