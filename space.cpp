#include <iostream>
#include <vector>
#include <cassert>

#include "space.h"
#include "cube.h"

using namespace std;


bool Space::_isInBounds(size_t x, size_t y, size_t z) const {
    return (x < this->width && y < this->height && z < this->depth);
}

bool Space::_is3D(vector<size_t> coordinate) const {
    return (coordinate.size() == 3);
}

void Space::_scale() {
    if (this->isEmpty()) {
        return;
    }

    if (
        this->cubes.size() == this->width &&
        this->cubes[0].size() == this->height &&
        this->cubes[0][0].size() == this->depth
    ) {
        return;
    }

    this->cubes.resize(this->width);
    for (int i=0; i<this->width; i++) {
        this->cubes[i].resize(this->height);
        for (int j=0; j<this->height; j++) {
            this->cubes[i][j].resize(this->depth);
        }
    }
}


Space::Space() {
    this->width = 0;
    this->height = 0;
    this->depth = 0;
}

Space::Space(size_t width, size_t height, size_t depth) {
    /* If any of these values are 0, the space will seem empty */
    assert(width > 0);
    assert(height > 0);
    assert(depth > 0);
    
    this->width = width;
    this->height = height;
    this->depth = depth;

    this->_scale();
}

Space::~Space() {
    if (this->isEmpty()) {
        return;
    }

    this->width = 0;
    this->height = 0;
    this->depth = 0;
    this->_scale();

}

void Space::setWidth(size_t width) {
    assert(width > 0);
    this->width = width;
    this->_scale();
}
void Space::setHeight(size_t height) {
    assert(height > 0);
    this->height = height;
    this->_scale();
}
void Space::setDepth(size_t depth) {
    assert(depth > 0);
    this->depth = depth;
    this->_scale();
}

size_t Space::getWidth() const {
    return this->width;
}
size_t Space::getHeight() const {
    return this->height;
}
size_t Space::getDepth() const {
    return this->depth;
}

void Space::setCube(size_t x, size_t y, size_t z, Cube cube) {
    assert(this->_isInBounds(x, y, z));
    this->cubes[x][y][z] = cube;
}
void Space::setCube(vector<size_t> coordinate, Cube cube) {
    assert(this->_is3D(coordinate));
    assert(this->_isInBounds(coordinate[0], coordinate[1], coordinate[2]));
    this->setCube(coordinate[0], coordinate[1], coordinate[2], cube);
}

Cube& Space::getCube(size_t x, size_t y, size_t z) {
    assert(this->_isInBounds(x, y, z));
    return this->cubes[x][y][z];
}
Cube& Space::getCube(vector<size_t> coordinate) {
    assert(this->_is3D(coordinate));
    assert(this->_isInBounds(coordinate[0], coordinate[1], coordinate[2]));
    return this->getCube(coordinate[0], coordinate[1], coordinate[2]);
}

bool Space::moveBlocked(vector<size_t> start, vector<size_t> end) const {
    assert(this->_is3D(start));
    assert(this->_is3D(end));

    return false;
}

bool Space::isEmpty() const {
    return (this->width == 0 || this->height == 0 || this->depth == 0);
}



