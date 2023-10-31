#include <string>
#include "cube.h"

using namespace std;

Cube::Cube() {
    this->side = false;
    this->front = false;
    this->bottom = false;
}

Cube::Cube(bool side, bool front, bool bottom) {
    this->side = side;
    this->front = front;
    this->bottom = bottom;
}

Cube::~Cube() {}

void Cube::setSide(bool side) {
    this->side = side;
}
void Cube::setFront(bool front) {
    this->front = front;
}
void Cube::setBottom(bool bottom) {
    this->bottom = bottom;
}

void Cube::unsetSide() {
    this->side = false;
}
void Cube::unsetFront() {
    this->front = false;
}
void Cube::unsetBottom() {
    this->bottom = false;
}

bool Cube::hasSide() const {
    return this->side;
}
bool Cube::hasFront() const {
    return this->front;
}
bool Cube::hasBottom() const {
    return this->bottom;
}

string Cube::toString() {
    string str = "Cube: ";
    if (this->hasSide()) {
        str += "Side ";
    }
    if (this->hasFront()) {
        str += "Front ";
    }
    if (this->hasBottom()) {
        str += "Bottom ";
    }
    return str;
}
    