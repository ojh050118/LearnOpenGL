#ifndef LEARNOPENGL_GLFW_WINDOW_H
#define LEARNOPENGL_GLFW_WINDOW_H


typedef void(*DrawCallback)();

class GLFWWindow {
private:
    GLFWwindow *window;
    DrawCallback drawCallback;
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void onDraw();
    void processInput();

public:
    GLFWWindow(int glMajorVersion, int glMinorVersion);
    void Create(int width, int height, const char *title);
    void Close();
    bool Exists();
    void SetOnDraw(DrawCallback cb);
};


#endif //LEARNOPENGL_GLFW_WINDOW_H
