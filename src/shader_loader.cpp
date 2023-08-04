#include <iostream>
#include <fstream>
#include <sstream>
#include "shader_loader.h"

std::string ShaderLoader::LoadShader(bool isVertexShader, std::string name) {
    std::string shaderExtension = isVertexShader ? ".vs" : ".fs";
    std::string fileName = "shaders/" + name + shaderExtension;
    std::ifstream file(fileName);
    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}