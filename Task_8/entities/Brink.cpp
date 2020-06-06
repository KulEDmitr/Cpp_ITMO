#include "Brink.h"

Brink::~Brink() {
    data->~Color();
}

void Brink::setColor(int num) {
    plane = num;
    float r, g, b;
    switch (plane) {
        case 0:
            r = 1.0f;
            g = 0.0f;
            b = 1.0f;
            break;
        case 1:
            r = 0.0f;
            g = 0.0f;
            b = 1.0f;
            break;
        case 2:
            r = 0.0f;
            g = 1.0f;
            b = 1.0f;
            break;
        case 3:
            r = 0.0f;
            g = 1.0f;
            b = 0.0f;
            break;
        case 4:
            r = 1.0f;
            g = 0.0f;
            b = 0.0f;
            break;
        case 5:
            r = 1.0f;
            g = 1.0f;
            b = 0.0f;
            break;
    }
    data->setColor(r, g, b);
}

int Brink::getPlane() const {return plane;}

Color *Brink::getData() const {return data;}

void Color::setColor(float rr, float gg, float bb) {
    r = rr;
    g = gg;
    b = bb;
}
