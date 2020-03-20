#include <cmath>
#include "PhysObject.h"

double PhysObject::mass() { return mass_; }

bool PhysObject::operator==(const PhysObject &ob) const {
    return fmax(mass_, ob.mass_) - fmin(mass_, ob.mass_) < PRECISION;
}

bool PhysObject::operator<(const PhysObject &ob) const { return mass_ < ob.mass_; }
