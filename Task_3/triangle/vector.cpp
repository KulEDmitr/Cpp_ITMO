#include <cmath>
#include "vector.h"

double get_len(vector const &a, vector const &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

vector::vector(double x, double y) : x(x), y(y) {}

vector &vector::operator+=(vector const &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

vector operator+(vector v, vector const &rhs) { return v += rhs; }

vector operator+(vector const &rhs, vector v) { return v += rhs; }


std::string vector::to_string() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }

std::ostream &operator<<(std::ostream &s, vector const &a) { return s << a.to_string(); }

std::istream &operator>>(std::istream &s, vector &a) {
    double x = 0, y = 0;
    s >> x >> y;
    a = *new vector(x, y);
    return s;
}
