//
// Created by 오준호 on 2022/11/21.
//

#ifndef LEARNOPENGL_SHADER_H
#define LEARNOPENGL_SHADER_H

const char *vertexShaderSource = "#version 330 core\n"
                            "layout (location = 0) in vec3 aPos;\n"
                            "\n"
                            "void main()\n"
                            "{\n"
                            "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                            "}";

const char *fragmentShaderSource = "#version 330 core\n"
                              "out vec4 FragColor;\n"
                              "\n"
                              "void main()\n"
                              "{\n"
                              "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                              "}";

#endif //LEARNOPENGL_SHADER_H
