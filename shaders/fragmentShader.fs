#version 330 core

out vec4 fragColor;

void main() {
    vec3 col = vec3(0.3f, 0.5f, 0.7f) * gl_FragCoord.x * 0.001;
    fragColor = vec4(col, 1.0f);
}