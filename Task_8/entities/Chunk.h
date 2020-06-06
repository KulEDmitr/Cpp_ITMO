#pragma once

#include "Brink.h"

class Chunk {
    Brink* chunk;

    float size, fx, fy, fz;
    int x, y, z;

    static void rotate(int&, int&);
    static void rotate_(int&, int&);
    void refresh();

public:
    explicit Chunk(float = 0, int = 0, int = 0, int = 0);
    ~Chunk();

    void setColor();
    void setColor(int, int);
    int getColor(int) const;
    int getX() const;
    int getY() const;
    int getZ() const;

    void draw() const;

    void rotateX();
    void rotateX_();
    void rotateY();
    void rotateY_();
    void rotateZ();
    void rotateZ_();
};
