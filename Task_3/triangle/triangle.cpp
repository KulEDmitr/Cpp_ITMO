#include <cmath>
#include <iostream>

#include "triangle.h"

triangle::triangle(vector const &a, vector const &b, vector const &c) : a(a), b(b), c(c) {}

double triangle::get_perimeter() const {
    return get_len(this->a, this->b) +
           get_len(this->b, this->c) +
           get_len(this->a, this->c);
}

double triangle::get_square() const {
    double perimeter = get_perimeter();
    return sqrt(perimeter * (perimeter - get_len(this->a, this->b)) *
                (perimeter - get_len(this->b, this->c)) *
                (perimeter - get_len(this->a, this->c)));
}

triangle &triangle::operator+=(vector const &v) {
    this->a += v;
    this->b += v;
    this->c += v;
    return *this;
}

triangle operator+(triangle a, vector const &v) {
    return a += v;
}

triangle operator+(vector const &v, triangle a) {
    return a += v;
}

bool operator==(triangle const &a, triangle const &b) {
    double first = a.get_square();
    double second = b.get_square();
    return (first > second) ?
           first < second + PRECISION :
           second < first + PRECISION;
}

bool operator!=(triangle const &a, triangle const &b) {
    return !(a == b);
}

bool operator<(triangle const &a, triangle const &b) {
    return (a != b) && a.get_square() < b.get_square();
}

bool operator>(triangle const &a, triangle const &b) {
    return (a != b) && b.get_square() < a.get_square();
}


std::string triangle::to_string() const {
    return "Hello, I'm a triangle with\nPoint 1: " + a.to_string() + "\nPoint 2: " + b.to_string() + "\nPoint 3: " +
           c.to_string();
}

std::ostream &operator<<(std::ostream &s, triangle const &a) {
    return s << a.to_string();
}
std::istream &operator>>(std::istream &s, triangle &tr) {
    vector a, b, c;
    s >> a >> b >> c;
    tr = *new triangle(a, b, c);
    return s;
}