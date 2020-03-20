#pragma once

#include "../Vector2D.h"

class PhysObject;

// Интерфейс "Физический объект".
class IPhysObject {
public:
// Масса, кг.
    virtual double mass() = 0;

// Координаты центра масс, м.
    virtual Vector2D position() = 0;

// Сравнение по массе.
    virtual bool operator==(const PhysObject &ob) const = 0;

// Сравнение по массе.
    virtual bool operator<(const PhysObject &ob) const = 0;
};
