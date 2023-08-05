#ifndef LEARNOPENGL_VERTEX_H
#define LEARNOPENGL_VERTEX_H
#include "vector2.h"
#include "color4.h"


struct Vertex {
public:
    Vector2 Position = Vector2(0, 0);
    float Depth = 0;
    Color4 Color = Color4(1, 1, 1, 1);
    Vertex(Vector2 pos, Color4 col) {
        Position = pos;
        Color = col;
    }
};


#endif //LEARNOPENGL_VERTEX_H
