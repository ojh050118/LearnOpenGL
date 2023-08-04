#ifndef LEARNOPENGL_COLOR4_H
#define LEARNOPENGL_COLOR4_H


struct Color4 {
public:
    float R;
    float G;
    float B;
    float A;
    Color4(float r, float g, float b, float a) {
        R = r;
        G = g;
        B = b;
        A = a;
    }
};


#endif //LEARNOPENGL_COLOR4_H
