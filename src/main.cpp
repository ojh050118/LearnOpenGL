#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shader_loader.h"
#include "glfw_window.h"
#include "vertex.h"
#include "vector2.h"
#include "color4.h"

void onDraw() {
    Vertex vertices[] = {
            Vertex(Vector2(0.0f, 0.5f), Color4(1, 0, 0, 1)),
            Vertex(Vector2(-0.5f, -0.5f), Color4(0, 1, 0, 1)),
            Vertex(Vector2(0.5f, -0.5f), Color4(0, 0, 1, 1)),
    };

    unsigned int vbo, vao;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof (float), (void*)offsetof(Vertex, Color));
    glEnableVertexAttribArray(1);

    ShaderLoader shaders = ShaderLoader();
    std::string vsSource = shaders.LoadShader(true, "vertexShader");
    std::string fsSource = shaders.LoadShader(false, "fragmentShader");
    const char *vs = vsSource.c_str();
    const char *fs = fsSource.c_str();

    unsigned int vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexShader, 1, &vs, nullptr);
    glShaderSource(fragmentShader, 1, &fs, nullptr);
    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

int main() {
    GLFWWindow window = GLFWWindow(3, 3);
    window.SetOnDraw(onDraw);
    window.Create(800, 600, "LearnOpenGL");
    window.Run();

    return 0;
}
