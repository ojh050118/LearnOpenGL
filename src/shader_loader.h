#ifndef LEARNOPENGL_SHADER_LOADER_H
#define LEARNOPENGL_SHADER_LOADER_H


class ShaderLoader {
public:
    std::string load_shader(bool isVertexShader, std::string name);
};


#endif //LEARNOPENGL_SHADER_LOADER_H
