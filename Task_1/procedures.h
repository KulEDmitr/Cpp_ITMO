#ifndef TASK_1_PROCEDURES_H
#define TASK_1_PROCEDURES_H

#include <iostream>

void swap(int &, int &);
void swap(int *, int *);

void floor(double &);
void floor(double *);

struct complex {
    double re;
    double im;

    complex(double re, double im);
};

void mult_compl_real(complex &, double const &);
void mult_compl_real(complex *, double const *);

struct vector {
    double x;
    double y;

    vector(double x, double y);
};

struct circle {
    vector centre = vector(0, 0);
    double r;

    circle(double x, double y, double r);
};

void move_circle(circle &, vector const &);
void move_circle(circle *, vector const *);

std::ostream &operator<<(std::ostream &s, complex const &z);
std::ostream &operator<<(std::ostream &s, circle const &c);
std::ostream &operator<<(std::ostream &s, vector const &v);
#endif
