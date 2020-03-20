#include <cmath>
#include <iostream>

#include "Circle.h"

double Circle::square() { return M_PI * radius * radius; }
double Circle::perimeter() { return 2 * M_PI * radius; }

Vector2D Circle::position() { return center; }

void Circle::draw() {
    std::cout << "Hello, I'm a circle with:\n\tcentre: ";
    center.draw();
    std::cout << "\n\tradius: " << radius << "\n\tmass: " << mass_ << std::endl;
}

void Circle::initFromDialog() {
    std::cout << "Hello, I'm a circle\nPlease, enter some parameter for me\ncoordinates of center (x, y), "
                 "radius length and mass\nx (real number):" << std::endl;
    std::cin >> center.x;
    std::cout << "y (real number):" << std::endl;
    std::cin >> center.y;
    std::cout << "radius length (real number):" << std::endl;
    std::cin >> radius;
    std::cout << "mass (real number):" << std::endl;
    std::cin >> mass_;
    std::cout << "Thank you, I'm created";
}

const char *Circle::classname() { return "Circle"; }
unsigned int Circle::size() { return sizeof(Circle); }
