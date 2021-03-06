#include <cmath>
#include <iostream>

#include "Rectangle.h"

double Rectangle::square() {
    return checkAndReturn([](double d1, double d2, double d3) { return d1 * d2; });
}

double Rectangle::perimeter() {
    return checkAndReturn([](double d1, double d2, double d3) { return (d1 + d2) * 2; });
}

Vector2D Rectangle::position() {
    double l1 = getDistance(a, b);
    double l2 = getDistance(a, c);
    double l3 = getDistance(a, d);

    Vector2D point;
    if (l1 > l2 || l1 > l3) {
        point.x = b.x;
        point.y = b.y;
    } else if (l2 > l1 && l2 > l3) {
        point.x = c.x;
        point.y = c.y;
    } else {
        point.x = d.x;
        point.y = d.y;
    }
    point.x  = (point.x + a.x) / 2;
    point.y  = (point.y + a.y) / 2;
    return point;
}

void Rectangle::draw() {
    std::cout << "Hello, I'm a rectangle with:\n\tpoint 1: ";
    a.draw();
    std::cout << "\n\tpoint 2: ";
    b.draw();
    std::cout << "\n\tpoint 3: ";
    c.draw();
    std::cout << "\n\tpoint 4: ";
    d.draw();
    std::cout << "\n\tmass: " << mass_ << std::endl;
}

void Rectangle::initFromDialog() {
    std::cout << "Hello, I'm a rectangle\nPlease, enter some parameter for me\n"
                 "coordinates of my vertexes (x, y), and mass\npoint 1: (x, y) (real numbers):" << std::endl;
    std::cin >> a.x >> a.y;
    std::cout << "point 2: (x, y) (real numbers):" << std::endl;
    std::cin >> b.x >> b.y;
    std::cout << "point 3: (x, y) (real numbers):" << std::endl;
    std::cin >> c.x >> c.y;
    std::cout << "point 4: (x, y) (real numbers):" << std::endl;
    std::cin >> d.x >> d.y;
    std::cout << "mass (real number):" << std::endl;
    std::cin >> mass_;
    if (checkData()) {
        std::cout << "Thank you, I'm created";
    } else {
        this->~Rectangle();
        throw std::runtime_error("I can't be created with that data. Please check the parameters");
    }
}

const char *Rectangle::classname() {
    return "Rectangle";
}

unsigned int Rectangle::size() {
    return sizeof(Rectangle);
}

double Rectangle::checkAndReturn(const std::function<double(double, double, double)> &function) {
    double l1 = getDistance(a, b);
    double l2 = getDistance(a, c);
    double l3 = getDistance(a, d);

    double res;
    if (l1 > l2 || l1 > l3) {
        res = function(l2, l3, l1);
    } else if (l2 > l1 && l2 > l3) {
        res = function(l1, l3, l2);
    } else {
        res = function(l1, l2, l3);
    }
    return res;
}

bool Rectangle::checkData() {
    double res = checkAndReturn([](double d1, double d2, double d3) { return d1 * d1 + d2 * d2 - d3 * d3; });
    return fmax(res, 0.0) - fmin(res, 0.0) < PRECISION;
}
