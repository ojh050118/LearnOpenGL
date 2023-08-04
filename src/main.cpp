#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shader_loader.h"
#include "glfw_window.h"

void onDraw() {
    // 삼각형을 그려낼 정점들. (x, y, z) 순서.
    float vertices[] = {
            0.0f, 0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f
    };

    // Vertex Bufer Object, Vertex Array Object
    // 포인터 역할만 함.
    unsigned int VBO, VAO;

    // 버퍼를 사용할 준비.
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // VAO를 먼저 바인딩 해준 뒤, VBO 바인딩과 정점 속성들을 구성.
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    ShaderLoader shaders = ShaderLoader();

    std::string vsSource = shaders.LoadShader(true, "vertexShader");
    const char *vs = vsSource.c_str();

    // Vertex 쉐이더 준비
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vs, NULL);
    glCompileShader(vertexShader);

    std::string fsSource = shaders.LoadShader(false, "fragmentShader");
    const char *fs = fsSource.c_str();

    // Fragment 쉐이더 준비
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fs, NULL);
    glCompileShader(fragmentShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // 쉐이더 연결
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main() {
    GLFWWindow window = GLFWWindow(3, 3);
    window.SetOnDraw(onDraw);
    window.Create(800, 600, "LearnOpenGL");
    window.Run();

    return 0;
}
