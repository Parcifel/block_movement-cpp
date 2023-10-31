#include "blocked.h"
#include "space.h"
#include "cube.h"
#include <cmath>
#include <cassert>
#include <vector>
#include <string>   

#include <iostream>

using namespace std;

template <typename T>
string vectorString(vector<T> vect) {
    string str = "[";
    for (int i=0; i<vect.size(); i++) {
        str += to_string(vect[i]);
        if (i != vect.size() - 1) {
            str += ", ";
        }
    }
    str += "]";
    return str;
}

size_t countDifferent(vector<size_t> start, vector<size_t> end) {
    assert(start.size() == end.size());

    size_t diff = 0;
    for (int i=0; i<start.size(); i++) {
        if (start[i] != end[i]) {
            diff++;
        }
    }

    return diff;
}

bool is1DMove(vector<size_t> start, vector<size_t> end) {
    return (countDifferent(start, end) == 1);
}
bool is2DMove(vector<size_t> start, vector<size_t> end) {
    return (countDifferent(start, end) == 2);
}
bool is3DMove(vector<size_t> start, vector<size_t> end) {
    return (countDifferent(start, end) == 3);
}

bool blockedInUnitX(Cube& start, Cube& end, int direction) {

    return (direction > 0) ? end.hasSide() : start.hasSide();  
}
bool blockedInUnitY(Cube& start, Cube& end, int direction) {
    return (direction > 0) ? end.hasBottom() : start.hasBottom();  
}
bool blockedInUnitZ(Cube& start, Cube& end, int direction) {
    return (direction > 0) ? end.hasFront() : start.hasFront();  
}

bool blocked1D(Space& space, vector<size_t> start, vector<size_t> end) {
    /**
     * First determine what direction the move is in.
     * Then, determine if the move is blocked.
    */
    assert(is1DMove(start, end));

    int x_direction = end[0] - start[0];
    int y_direction = end[1] - start[1];
    int z_direction = end[2] - start[2];

    Cube start_cube = space.getCube(start[0], start[1], start[2]);
    Cube end_cube = space.getCube(end[0], end[1], end[2]);

    if (x_direction != 0) {
        return blockedInUnitX(start_cube, end_cube, x_direction);
    } else if (y_direction != 0) {
        return blockedInUnitY(start_cube, end_cube, y_direction);
    } else if (z_direction != 0) {
        return blockedInUnitZ(start_cube, end_cube, z_direction);
    } else {
        return false;
    }
}
bool blocked2D(Space& space, vector<size_t> start, vector<size_t> end) {
    return false;
}
bool blocked3D(Space& space, vector<size_t> start, vector<size_t> end) {
    return false;
}

bool moveBlocked(Space& space, vector<size_t> start, vector<size_t> end) {
    if (is1DMove(start, end)) {
        return blocked1D(space, start, end);
    } else if (is2DMove(start, end)) {
        return blocked2D(space, start, end);
    } else if (is3DMove(start, end)) {
        return blocked3D(space, start, end);
    } else {
        return false;
    }
}