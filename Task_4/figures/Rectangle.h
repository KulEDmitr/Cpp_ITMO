#pragma once

#include <functional>

#include "abstract/Figure.h"

/*
a1-----a2
|       |
a3-----a4
*/

struct Rectangle : Figure {
    explicit Rectangle(double mass = 0, double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0,
                       double x3 = 0, double y3 = 0, double x4 = 0, double y4 = 0) :
            Figure(mass), a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4) {};

    ~Rectangle() override = default;

    double square() override;
    double perimeter() override;

    Vector2D position() override;

    void draw() override;

    void initFromDialog() override;

    const char *classname() override;
    unsigned int size() override;

private:
    Vector2D a, b, c, d;

    double checkAndReturn(const std::function<double(double, double, double)>&);
    bool checkData();
};