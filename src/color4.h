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

    static Color4 White() {
        return {1, 1, 1, 1};
    }

    static Color4 Black() {
        return {0, 0, 0, 1};
    }

    static Color4 Red() {
        return {1, 0, 0, 1};
    }

    static Color4 Green() {
        return {0, 1, 0, 1};
    }

    static Color4 Blue() {
        return {0, 0, 1, 1};
    }

    static Color4 Yellow() {
        return {1, 1, 0, 1};
    }

    static Color4 Transparent() {
        return {1, 1, 1, 0};
    }
};


#endif //LEARNOPENGL_COLOR4_H
