#pragma once

// Интерфейс "Геометрическая фигура".
class IGeoFig {
public:
// Площадь.
    virtual double square() = 0;

// Периметр.
    virtual double perimeter() = 0;
};
