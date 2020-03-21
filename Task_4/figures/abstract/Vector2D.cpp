#include "Vector2D.h"

Vector2D::Vector2D(double x, double y) : CVector2D() {
    this->x = x;
    this->y = y;
}

double Vector2D::length() { return sqrt(x * x + y * y); }

void Vector2D::draw() { std::cout << "(" << x << ", " << y << ")"; }

double getDistance(Vector2D const &from, Vector2D const &to) {
    double x = fmax(from.x, to.x) - fmin(from.x, to.x);
    double y = fmax(from.y, to.y) - fmin(from.y, to.y);
    return sqrt(x * x + y * y);
}
