#pragma once

#include "vector.h"

double const PRECISION = 0.000001;

struct triangle {
    explicit triangle(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0, double x3 = 0, double y3 = 0) :
            a(x1, y1), b(x2, y2), c(x3, y3) {}

    triangle(vector const &, vector const &, vector const &);
    triangle(triangle const &) = default;

    ~triangle() = default;

    double get_perimeter() const;
    double get_square() const;
    std::string to_string() const;

    friend bool operator==(triangle const &, triangle const &);
    friend bool operator!=(triangle const &, triangle const &);
    friend bool operator<(triangle const &, triangle const &);
    friend bool operator>(triangle const &, triangle const &);

    triangle &operator+=(vector const &);

    friend triangle operator+(triangle, vector const &);
    friend triangle operator+(vector const &, triangle);

private:
    vector a, b, c;
};

triangle operator+(triangle, vector const &);
triangle operator+(vector const &, triangle);

std::ostream &operator<<(std::ostream &s, triangle const &a);
std::istream &operator>>(std::istream &s, triangle &tr);
