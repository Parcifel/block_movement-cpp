#include <iostream>
#include <vector>
#include <cassert>

#include "space.h"
#include "cube.h"

using namespace std;

bool Space::_isInBounds(vector<size_t> coordinate) const {
    if (coordinate.size() == 1) {
        return this->_isInBounds(coordinate[0], 0, 0);
    } else if (coordinate.size() == 2) {
        return this->_isInBounds(coordinate[0], coordinate[1], 0);
    } else if (coordinate.size() == 3) {
        return this->_isInBounds(coordinate[0], coordinate[1], coordinate[2]);
    } else {
        cerr << "Invalid coordinate size: " << coordinate.size() << endl;
        assert(false);
    }
}
bool Space::_isInBounds(size_t x, size_t y, size_t z) const {
    if (this->_is1D()) {
        return (x < this->m_width);
    } else if (this->_is2D()) {
        return (x < this->m_width && y < this->m_height);
    } else if (this->_is3D()) {
        return (x < this->m_width && y < this->m_height && z < this->m_depth);
    } else {
        return false;
    }
}

bool Space::_is1D() const {
    return (this->m_width > 0 && this->m_height == 0 && this->m_depth == 0);
}
bool Space::_is2D() const {
    return (this->m_width > 0 && this->m_height > 0 && this->m_depth == 0);
}
bool Space::_is3D() const {
    return (this->m_width > 0 && this->m_height > 0 && this->m_depth > 0);
}

void Space::_scale() {
    // There is nothing to scale
    if (this->isEmpty()) {
        return;
    }

    // Nothing changed
    if (
        this->cubes.size() == this->m_width &&
        this->cubes[0].size() == this->m_height &&
        this->cubes[0][0].size() == this->m_depth
    ) {
        return;
    }

    this->cubes.resize(this->m_width);
    for (int i=0; i<this->m_width; i++) {
        this->cubes[i].resize(this->m_height);
        for (int j=0; j<this->m_height; j++) {
            this->cubes[i][j].resize(this->m_depth);
        }
    }
}

void Space::_create(size_t width, size_t height, size_t depth) {
    this->m_width = width;
    this->m_height = height;
    this->m_depth = depth;

    this->_scale();
}

void Space::_setCube(size_t x, size_t y, size_t z, Cube cube) {
    assert(this->_isInBounds(x, y, z));
    this->cubes[x][y][z] = cube;
}
Cube& Space::_getCube(size_t x, size_t y, size_t z) {
    assert(this->_isInBounds(x, y, z));
    return this->cubes[x][y][z];
}

/* Constructors */
Space::Space() {
    this->_create(0, 0, 0);
}
Space::Space(size_t width) {
    this->_create(width, 0, 0);
}
Space::Space(size_t width, size_t height) {
    this->_create(width, height, 0);
}
Space::Space(size_t width, size_t height, size_t depth) {
    this->_create(width, height, depth);
}

/* Destructor */
Space::~Space() {
    if (this->isEmpty()) {
        return;
    }

    this->m_width = 0;
    this->m_height = 0;
    this->m_depth = 0;
    this->_scale();

}

/* Mutators */
void Space::resize(size_t width) {
    this->_create(width, 0, 0);
}
void Space::resize(size_t width, size_t height) {
    this->_create(width, height, 0);
}
void Space::resize(size_t width, size_t height, size_t depth) {
    this->_create(width, height, depth);
}

/* Accessors */
size_t Space::width() const {
    return this->m_width;
}
size_t Space::height() const {
    return this->m_height;
}
size_t Space::depth() const {
    return this->m_depth;
}
size_t Space::size() const {
    return this->m_width * this->m_height * this->m_depth;
}
vector<size_t> Space::dimentions() const {
    if (this->isEmpty()) {
        return {};
    } else if (this->_is1D()) {
        return {this->m_width};
    } else if (this->_is2D()) {
        return {this->m_width, this->m_height};
    } else if (this->_is3D()) {
        return {this->m_width, this->m_height, this->m_depth};
    } else {
        cerr << "TF: Invalid dimentions" << endl;
        assert(false);
    }
}


/* Methods */
void Space::setCube(size_t x, Cube cube) {
    assert(this->_is1D());
    assert(this->_isInBounds(x, 0, 0));
    this->setCube(x, 0, 0, cube);
}
void Space::setCube(size_t x, size_t y, Cube cube) {
    assert(this->_is2D());
    assert(this->_isInBounds(x, y, 0));
    this->setCube(x, y, 0, cube);
}
void Space::setCube(size_t x, size_t y, size_t z, Cube cube) {
    assert(this->_is3D());
    assert(this->_isInBounds(x, y, z));
    this->_setCube(x, y, z, cube);
}
void Space::setCube(vector<size_t> coordinate, Cube cube) {
    if (coordinate.size() == 1) {
        this->setCube(coordinate[0], cube);
    } else if (coordinate.size() == 2) {
        this->setCube(coordinate[0], coordinate[1], cube);
    } else if (coordinate.size() == 3) {
        this->setCube(coordinate[0], coordinate[1], coordinate[2], cube);
    } else {
        cerr << "Invalid coordinate size: " << coordinate.size() << endl;
        assert(false);
    }
}


Cube& Space::getCube(size_t x) {
    assert(this->_is1D());
    return this->_getCube(x, 0, 0);
}
Cube& Space::getCube(size_t x, size_t y) {
    assert(this->_is2D());
    return this->_getCube(x, y, 0);
}
Cube& Space::getCube(size_t x, size_t y, size_t z) {
    assert(this->_is3D());
    return this->_getCube(x, y, z);
}
Cube& Space::getCube(vector<size_t> coordinate) {
    if (this->_is1D()) {
        assert(coordinate.size() == 1);
        return this->_getCube(coordinate[0], 0, 0);
    } else if (this->_is2D()) {
        assert(coordinate.size() == 2);
        return this->_getCube(coordinate[0], coordinate[1], 0);
    } else if (this->_is3D()) {
        assert(coordinate.size() == 3);
        return this->_getCube(coordinate[0], coordinate[1], coordinate[2]);
    } else {
        cerr << "TF: Invalid dimentions" << endl;
        assert(false);
    }
}

bool Space::isEmpty() const {
    return (this->m_width == 0 && this->m_height == 0 && this->m_depth == 0);
}

Cube& Space::operator()(vector<size_t> coordinate) {
    return this->getCube(coordinate);
}
Cube& Space::operator()(size_t x) {
    return this->getCube(x);
}
Cube& Space::operator()(size_t x, size_t y) {
    return this->getCube(x, y);
}
Cube& Space::operator()(size_t x, size_t y, size_t z) {
    return this->getCube(x, y, z);
}

ostream& operator<<(ostream& os, Space& space) {
    os << space.toString();
    return os;
}
string Space::toString() const {
    string output="";

    if (this->isEmpty()) {
        output += "Empty space";
        return output;
    }

    vector<size_t> dim = this->dimentions();
    output += to_string(dim.size()) ;
    output += "D Space: [";

    for (size_t number : dim) {
        output += to_string(number) + " ";
    }
    output[output.size()-1] = ']';
    output += '\n';

    return output;
}



bool Space::moveBlocked(vector<size_t> start, vector<size_t> end) const {
    return false;
}