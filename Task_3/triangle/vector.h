#pragma once

#include <iostream>

struct vector {
    explicit vector(double = 0, double = 0);
    vector(vector const &) = default;

    vector &operator=(vector const &) = default;
    vector &operator+=(vector const &rhs);
    std::string to_string() const;

    friend double get_len(vector const &, vector const &);

    friend vector operator+(vector, vector const &);
    friend vector operator+(vector const &, vector);

private:
    double x, y;
};

double get_len(vector const &, vector const &);

vector operator+(vector, vector const &);
vector operator+(vector const &, vector);

std::ostream &operator<<(std::ostream &s, vector const &a);
std::istream &operator>>(std::istream &s, vector &a);
