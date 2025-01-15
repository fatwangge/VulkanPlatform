#version 450

layout(set = 0, binding = 1) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor; //no use
layout(location = 2) in vec2 inTexCoord; //no use
layout(location = 3) in vec3 inNormal; //no use

//layout(location = 0) out vec3 fragColor;
//layout(location = 1) out vec2 fragTexCoord;
layout(location = 0) out vec3 pos;

void main() {
    gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPosition, 1.0);
    gl_Position = gl_Position.xyww; //cheat in depth test
    //fragColor = inColor;
    //fragTexCoord = inTexCoord;
    pos = inPosition; //pass input position to fragment for cubemap sampler
}