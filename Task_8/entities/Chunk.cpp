#include <GL/glut.h>

#include "Chunk.h"

Chunk::Chunk(float size, int x, int y, int z) : size(size), x(x), y(y), z(z), fx(0.0), fy(0.0), fz(0.0) {
    chunk = new Brink[6];

    setColor();
    refresh();
}

Chunk::~Chunk() {
    for (auto i = 0; i < 6; ++i) {
        chunk[i].~Brink();
    }
    delete [] chunk;
}

void Chunk::refresh() {
    fx = ((float) x - 1.5f) * size;
    fy = ((float) y - 1.5f) * size;
    fz = ((float) z - 1.5f) * size;
}

void Chunk::setColor() {
    for (auto i = 0; i < 6; ++i) {
        setColor(i, i);
    }
}

void Chunk::setColor(int side, int color) {
    chunk[side].setColor(color);
}

int Chunk::getColor(int side) const {return chunk[side].getSide();}

void Chunk::draw() const{
    Color *cur;

    cur = chunk[0].getData();
    glColor3f(cur->r, cur->g, cur->b);
    glBegin(GL_QUADS);
    glVertex3f(fx, fy, fz);
    glVertex3f(fx, fy, fz - size);
    glVertex3f(fx + size, fy, fz - size);
    glVertex3f(fx + size, fy, fz);
    glEnd();

    cur = chunk[1].getData();
    glColor3f(cur->r, cur->g, cur->b);
    glBegin(GL_QUADS);
    glVertex3f(fx, fy, fz);
    glVertex3f(fx, fy + size, fz);
    glVertex3f(fx + size, fy + size, fz);
    glVertex3f(fx + size, fy, fz);
    glEnd();

    cur = chunk[2].getData();
    glColor3f(cur->r, cur->g, cur->b);
    glBegin(GL_QUADS);
    glVertex3f(fx + size, fy, fz);
    glVertex3f(fx + size, fy, fz - size);
    glVertex3f(fx + size, fy + size, fz - size);
    glVertex3f(fx + size, fy + size, fz);
    glEnd();

    cur = chunk[3].getData();
    glColor3f(cur->r, cur->g, cur->b);
    glBegin(GL_QUADS);
    glVertex3f(fx, fy, fz - size);
    glVertex3f(fx, fy + size, fz - size);
    glVertex3f(fx + size, fy + size, fz - size);
    glVertex3f(fx + size, fy, fz - size);
    glEnd();

    cur = chunk[4].getData();
    glColor3f(cur->r, cur->g, cur->b);
    glBegin(GL_QUADS);
    glVertex3f(fx, fy, fz);
    glVertex3f(fx, fy, fz - size);
    glVertex3f(fx, fy + size, fz - size);
    glVertex3f(fx, fy + size, fz);
    glEnd();

    cur = chunk[5].getData();
    glColor3f(cur->r, cur->g, cur->b);
    glBegin(GL_QUADS);
    glVertex3f(fx, fy + size, fz);
    glVertex3f(fx, fy + size, fz - size);
    glVertex3f(fx + size, fy + size, fz - size);
    glVertex3f(fx + size, fy + size, fz);
    glEnd();
}

void Chunk::rotateX() {
    Brink cur = chunk[0];
    chunk[0] = chunk[3];
    chunk[3] = chunk[5];
    chunk[5] = chunk[1];
    chunk[1] = cur;

    rotate(y, z);
    refresh();
}

void Chunk::rotateX_() {
    Brink cur = chunk[0];
    chunk[0] = chunk[1];
    chunk[1] = chunk[5];
    chunk[5] = chunk[3];
    chunk[3] = cur;

    rotate_(y, z);
    refresh();
}

void Chunk::rotateY() {
    Brink cur = chunk[1];
    chunk[1] = chunk[2];
    chunk[2] = chunk[3];
    chunk[3] = chunk[4];
    chunk[4] = cur;

    rotate(z, x);
    refresh();
}

void Chunk::rotateY_() {
    Brink cur = chunk[1];
    chunk[1] = chunk[4];
    chunk[4] = chunk[3];
    chunk[3] = chunk[2];
    chunk[2] = cur;

    rotate_(z, x);
    refresh();
}

void Chunk::rotateZ() {
    Brink cur = chunk[0];
    chunk[0] = chunk[4];
    chunk[4] = chunk[5];
    chunk[5] = chunk[2];
    chunk[2] = cur;

    rotate(y, x);
    refresh();
}

void Chunk::rotateZ_() {
    Brink cur = chunk[0];
    chunk[0] = chunk[2];
    chunk[2] = chunk[5];
    chunk[5] = chunk[4];
    chunk[4] = cur;

    rotate_(y, x);
    refresh();
}

void Chunk::rotate(int &t, int &r) {
    if (t == 0 && r == 0) {
        r = 2;
    } else if (t == 1 && r == 0) {
        t = 0;
        r = 1;
    } else if (t == 2 && r == 0) {
        t = 0;
    } else if (t == 2 && r == 1) {
        t = 1;
        r = 0;
    } else if (t == 2 && r == 2) {
        r = 0;
    } else if (t == 1 && r == 2) {
        t = 2;
        r = 1;
    } else if (t == 0 && r == 2) {
        t = 2;
    } else if (t == 0 && r == 1) {
        t = 1;
        r = 2;
    }
}

void Chunk::rotate_(int &t, int &r) {
    if (t == 0 && r == 0) {
        t = 2;
    } else if (t == 1 && r == 0) {
        t = 2;
        r = 1;
    } else if (t == 2 && r == 0) {
        r = 2;
    } else if (t == 2 && r == 1) {
        t = 1;
        r = 2;
    } else if (t == 2 && r == 2) {
        t = 0;
    } else if (t == 1 && r == 2) {
        t = 0;
        r = 1;
    } else if (t == 0 && r == 2) {
        t = 0;
        r = 0;
    } else if (t == 0 && r == 1) {
        t = 1;
        r = 0;
    }
}

int Chunk::getX() const { return x; }

int Chunk::getY() const { return y; }

int Chunk::getZ() const { return z; }
