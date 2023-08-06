#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "shader.h"
#include "glfw_window.h"
#include "vertex.h"
#include "vector2.h"
#include "color4.h"

void onDraw() {
    Vertex vertices[] = {
            Vertex(Vector2(0.5f, 0.5f), Color4::Blue()),
            Vertex(Vector2(-0.5f, 0.5f), Color4::Green()),
            Vertex(Vector2(-0.5f, -0.5f), Color4::Red()),
            Vertex(Vector2(0.5f, -0.5f), Color4::Yellow()),
    };

    unsigned int indices[] = {
            0, 1, 2,
            0, 2, 3
    };

    unsigned int vbo, vao, ebo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof (float), (void*)offsetof(Vertex, Color));
    glEnableVertexAttribArray(1);

    double time = glfwGetTime();

    Shader shader("vertexShader", "fragmentShader");
    shader.Use();

    shader.SetFloat("time", (float)time);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

int main() {
    GLFWWindow window = GLFWWindow(3, 3);
    window.SetOnDraw(onDraw);
    window.Create(800, 600, "LearnOpenGL");
    window.Run();

    return 0;
}
