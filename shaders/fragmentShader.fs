#version 330 core

out vec4 fragColor;
in vec4 vCol;

void main() {
    vec3 c = vec3(vCol.r, vCol.g, vCol.b) * gl_FragCoord.y * 0.002;
    fragColor = vec4(c, 1.0);
}