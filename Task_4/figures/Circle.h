#pragma once

#include "abstract/Figure.h"
#include "abstract/Vector2D.h"

struct Circle : Figure {
    explicit Circle(double mass = 0, double x = 0, double y = 0, double radius = 0) :
            Figure(mass), center(x, y), radius(radius) {}

    double square() override;
    double perimeter() override;

    Vector2D position() override;

    void draw() override;

    void initFromDialog() override;

    const char *classname() override;
    unsigned int size() override;

private:
    Vector2D center;
    double radius;
};
