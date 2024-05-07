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

    // uint는 GPU의 해당 버퍼의 별칭으로 사용됨.
    unsigned int vbo, vao, ebo;

    // OpenGL은 상태 머신(State Machine)이므로 상태를 번경해주면 계속 유지됨.
    // 따라서 필요에 맞게 바인딩을 해제하고 새로 바인딩을 해주어야 함.
    // 할당(Gen) > 바인딩(Bind) > 데이터(입력) 순으로 사용해야함.

    // 정점 버퍼 객체
    // 요소를 그리기위해 필요한 정보를 GPU에 저장함.
    // 첫번째 인자(n)은 개수를 의미함.
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 정점 배열 객체
    // 정점의 속성(좌표, 색상)을 구성하는 설정(읽는 방법)을 저장하는 객체.
    // 여러 속성과 오브젝트를 그릴 때마다 바인딩하는 것을 막을 수 있음.
    // 첫번째 인자(n)은 개수를 의미함.
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // 첫번째 인자(n)은 개수를 의미함.
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 정점(x, y, z, R, G, B, A) => 간격은 (float)4바이트 * 7.
    // 0번 속성엔 좌표(x, y, z), 1번 속성엔 색상(R, G, B, A)가 전달됨.
    // 크기는 Vector3 이면 3, Vector4 이면 4, 데이터의 개수.
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

    // VAO를 바인딩 한 뒤, 드로우 콜을 수행하면 됨.
    // EBO는 glDrawElements()를 호줄하고, 나머지는 glDrawArrays()를 호출함.
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
