#pragma once

#include <cmath>
#include <iostream>
#include "interfases/CVector2D.h"
#include "interfases/IPrintable.h"


struct Vector2D : CVector2D, IPrintable {
    explicit Vector2D(double = 0, double = 0);

    double length();

    void draw() override;
    
    friend double getDistance(Vector2D const&, Vector2D const&);
};




