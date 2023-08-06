#include <iostream>
#include <fstream>
#include <sstream>
#include "glad/glad.h"
#include "shader.h"

Shader::Shader(const std::string& vertexShaderName, const std::string& fragmentShaderName) {
    id = 0;

    std::string vsPath = "shaders/" + vertexShaderName + ".vs";
    std::string fsPath = "shaders/" + fragmentShaderName + ".fs";

    std::ifstream vs(vsPath), fs(fsPath);
    std::stringstream vsSource, fsSource;

    vsSource << vs.rdbuf();
    fsSource << fs.rdbuf();

    vs.close();
    fs.close();

    vsStr = vsSource.str();
    fsStr = fsSource.str();

    vertexShaderSource = vsStr.c_str();
    fragmentShaderSource = fsStr.c_str();

    compile();
}

void Shader::Use() const {
    glUseProgram(id);
}

unsigned int Shader::GetID() const {
    return id;
}

void Shader::SetInt(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value) const {
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::SetDouble(const std::string& name, double value) const {
    glUniform1d(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::SetBool(const std::string& name, bool value) const {
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::compile() {
    unsigned int vertex, fragment;
    int isCompiled;
    char infoLog[512];

    vertex = glCreateShader(GL_VERTEX_SHADER);
    fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, &vertexShaderSource, nullptr);
    glShaderSource(fragment, 1, &fragmentShaderSource, nullptr);

    glCompileShader(vertex);
    glCompileShader(fragment);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &isCompiled);
    if (!isCompiled)
    {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &isCompiled);
    if (!isCompiled)
    {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    id = glCreateProgram();
    glAttachShader(id, vertex);
    glAttachShader(id, fragment);
    glLinkProgram(id);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
