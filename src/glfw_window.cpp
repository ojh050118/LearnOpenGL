#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glfw_window.h"

void GLFWWindow::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void GLFWWindow::onDraw() {
    while (!glfwWindowShouldClose(window)) {
        processInput();

        drawCallback();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void GLFWWindow::processInput() {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

GLFWWindow::GLFWWindow(int glMajorVersion, int glMinorVersion) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glMajorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glMinorVersion);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void GLFWWindow::Create(int width, int height, const char *title) {
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (window == nullptr)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    onDraw();
}

void GLFWWindow::Close() {
    glfwSetWindowShouldClose(window, 1);
    glfwTerminate();
}

bool GLFWWindow::Exists() {
    return glfwWindowShouldClose(window);
}

void GLFWWindow::SetOnDraw(DrawCallback cb) {
    drawCallback = cb;
}
