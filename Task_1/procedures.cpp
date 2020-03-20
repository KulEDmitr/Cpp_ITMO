#include "procedures.h"

void swap(int &a, int &b) {
    int bank = a;
    a = b;
    b = bank;
}

void swap(int *a, int *b) {
    int bank = *a;
    *a = *b;
    *b = bank;
}

void floor(double &a) {
    a = (int)a;
}

void floor(double *a) {
    *a = (int)(*a);
}

complex::complex(double re, double im) {
    this->re = re;
    this->im = im;
}

void mult_compl_real(complex &z, double const &a) {
    z.re *= a;
    z.im *= a;
}

void mult_compl_real(complex *z, double const *a) {
    (*z).re *= *a;
    z->im *= *a;
}

vector::vector(double x, double y) {
    this->x = x;
    this->y = y;
}

circle::circle(double x, double y, double r) {
    this->centre = vector(x, y);
    this->r = r;
}

void move_circle(circle &c, vector const &v) {
    c.centre.x += v.x;
    c.centre.y += v.y;
}

void move_circle(circle *c, vector const *v) {
    c->centre.x += v->x;
    c->centre.y += v->y;
}


std::ostream &operator<<(std::ostream &s, complex const &z) {
    return s << z.re << " + (" << z.im << ")i";
}

std::ostream &operator<<(std::ostream &s, circle const &c) {
    return s << "centre: (" << c.centre.x << ", " << c.centre.y << "), radius: " << c.r;
}

std::ostream &operator<<(std::ostream &s, vector const &v) {
    return s << "(" << v.x << ", " << v.y << ")";
}
