#pragma once

#include "interfases/IGeoFig.h"
#include "interfases/IPrintable.h"
#include "interfases/IDialogInitiable.h"
#include "interfases/BaseCObject.h"
#include "PhysObject.h"

struct Figure : IGeoFig, IPrintable, IDialogInitiable, BaseCObject, PhysObject {
    explicit Figure(double mass = 0) : PhysObject(mass) {};
    ~Figure() override = default;

    const char *classname() override = 0;
    unsigned int size() override = 0;

    void initFromDialog() override = 0;

    double square() override = 0;
    double perimeter() override = 0;

    void draw() override = 0;

    Vector2D position() override = 0;
};
