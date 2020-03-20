#pragma once

#include "interfases/IPhysObject.h"

struct PhysObject : IPhysObject {
    double PRECISION = 0.000001;

    explicit PhysObject(double mass = 0) : mass_(mass){}
    virtual ~PhysObject() = default;

    double mass() override;
    Vector2D position() override = 0;

    bool operator==(const PhysObject &ob) const override;

    bool operator<(const PhysObject &ob) const override;

protected:
    double mass_;
};
