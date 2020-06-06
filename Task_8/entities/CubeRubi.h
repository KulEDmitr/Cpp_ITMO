#pragma once

#include "Chunk.h"

class CubeRubi {
    Chunk blocks[3][3][3];

    float size, fx, fy, fz;

    void refresh();

    void rotateX(int);
    void rotateX_(int);
    void rotateY(int);
    void rotateY_(int);
    void rotateZ(int);
    void rotateZ_(int);

public:
    explicit CubeRubi(float = 0, float = 0, float = 0, float = 0);
    ~CubeRubi() = default;

    void rotate(int side);
    void rotate_(int side);

    void draw();

    float getX() const;
    float getY() const;
    float getZ() const;
    float getSize() const;
    int getColor(int, int, int, int) const;
    int getColor(int, int) const;
};
