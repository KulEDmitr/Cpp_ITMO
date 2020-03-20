#include "Vector2D.h"

Vector2D::Vector2D(double x, double y) : CVector2D() {
    this->x = x;
    this->y = y;
}

double Vector2D::length() {return sqrt(x * x + y * y);}

void Vector2D::draw()  { std::cout << "(" << x << ", " << y << ")";}

double getDistance(Vector2D const& from, Vector2D const& to) {
    return sqrt((from.x - to.x) * (from.x - to.x) + (from.y - to.y) * (from.y - to.y));
}
