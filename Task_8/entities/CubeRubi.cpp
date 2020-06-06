#include "CubeRubi.h"

CubeRubi::CubeRubi(float size, float x, float y, float z) : size(size), fx(x), fy(y), fz(z) {
    for (auto i = 0; i < 3; ++i) {
        for (auto j = 0; j < 3; ++j) {
            for (auto k = 0; k < 3; ++k) {
                blocks[i][j][k] = Chunk(size, i, j, k);
            }
        }
    }
}

void CubeRubi::draw() {
    for (auto &block : blocks) {
        for (auto &j : block) {
            for (auto &k : j) {
                k.draw();
            }
        }
    }
}

float CubeRubi::getX() const { return fx; }
float CubeRubi::getY() const { return fy; }
float CubeRubi::getZ() const { return fz; }

float CubeRubi::getSize() const { return size; }

int CubeRubi::getColor(int side, int x, int y, int z) const { return blocks[x][y][z].getColor(side); }
int CubeRubi::getColor(int side, int num) const {
    int pos1, pos2, curX = 0, curY = 0, curZ = 0;

    pos1 = (num - 1) - 3 * ((num - 1) / 3);
    pos2 = 2 - (num - 1) / 3;

    --side;
    switch (side) {
        case 0:
            curX = pos1;
            curY = 0;
            curZ = pos2;
            break;
        case 1:
            curX = pos1;
            curY = pos2;
            curZ = 2;
            break;
        case 2:
            curX = 2;
            curY = pos2;
            curZ = 2 - pos1;
            break;
        case 3:
            curX = 2 - pos1;
            curY = pos2;
            curZ = 0;
            break;
        case 4:
            curX = 0;
            curY = pos2;
            curZ = pos1;
            break;
        case 5:
            curX = pos1;
            curY = 2;
            curZ = 2 - pos2;
            break;
        default:
            break;
    }

    return blocks[curX][curY][curZ].getColor(side) + 1;
}

void CubeRubi::refresh() {
    Chunk curBlocks[3][3][3];

    for (auto & block : blocks) {
        for (auto & j : block) {
            for (auto & k : j) {
                Chunk* cur = &k;
                curBlocks[cur->getX()][cur->getY()][cur->getZ()] = k;
            }
        }
    }

    for (auto i = 0; i < 3; ++i) {
        for (auto j = 0; j < 3; ++j) {
            for (auto k = 0; k < 3; ++k) {
                blocks[i][j][k] = curBlocks[i][j][k];
            }
        }
    }
}

void CubeRubi::rotateX(int side) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            blocks[side][i][j].rotateX();
        }
    }
}
void CubeRubi::rotateX_(int side) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            blocks[side][i][j].rotateX_();
        }
    }
}

void CubeRubi::rotateY(int side) {
    for (auto & block : blocks) {
        for (int j = 0; j < 3; ++j) {
            block[side][j].rotateY();
        }
    }
}
void CubeRubi::rotateY_(int side) {
    for (auto & block : blocks) {
        for (int j = 0; j < 3; ++j) {
            block[side][j].rotateY_();
        }
    }
}

void CubeRubi::rotateZ(int side) {
    for (int i = 0; i < 3; ++i) {
        for (auto & block : blocks) {
            block[i][side].rotateZ();
        }
    }
}
void CubeRubi::rotateZ_(int side) {
    for (int i = 0; i < 3; ++i) {
        for (auto & block : blocks) {
            block[i][side].rotateZ_();
        }
    }
}

void CubeRubi::rotate(int side) {
    --side;
    switch (side) {
        case 0:
            rotateX_(0);
            break;
        case 1:
            rotateZ_(2);
            break;
        case 2:
            rotateX(2);
            break;
        case 3:
            rotateZ(0);
            break;
        case 4:
            rotateX_(0);
            break;
        case 5:
            rotateY(2);
            break;
        default:
            break;
    }
}
void CubeRubi::rotate_(int side) {
    --side;
    switch (side) {
        case 0:
            rotateX(0);
            break;
        case 1:
            rotateZ(2);
            break;
        case 2:
            rotateX_(2);
            break;
        case 3:
            rotateZ_(0);
            break;
        case 4:
            rotateX(0);
            break;
        case 5:
            rotateY_(2);
            break;
        default:
            break;
    }
}
