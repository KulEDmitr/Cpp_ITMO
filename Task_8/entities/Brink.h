#pragma once

enum class Colors {
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    WHITE = 5,
    ORANGE = 6,
    DEFAULT = 7
};

struct Color {
    float r, g, b;

    explicit Color(float r = 0.0f, float g = 0.0f, float b = 0.0f) : r(r), g(g), b(b) {};
    ~Color() = default;

    void setColor(float , float , float);
};

class Brink {
    int plane;
    Color* data;

public:
    Brink() : plane(0), data(new Color()) {}
    ~Brink();

    Color* getData() const;
    void setColor(int);
    int getPlane() const;
};
