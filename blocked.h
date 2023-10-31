#ifndef BLOCKED_H
#define BLOCKED_H

#include "space.h"
#include "cube.h"

size_t countDifferent(vector<size_t> start, vector<size_t> end);

bool is1DMove(vector<size_t> start, vector<size_t> end);
bool is2DMove(vector<size_t> start, vector<size_t> end);
bool is3DMove(vector<size_t> start, vector<size_t> end);

bool blockedInUnitX(Cube& start, Cube& end, int direction);
bool blockedInUnitY(Cube& start, Cube& end, int direction);
bool blockedInUnitZ(Cube& start, Cube& end, int direction);

bool blocked1D(Space& space, vector<size_t> start, vector<size_t> end);
bool blocked2D(Space& space, vector<size_t> start, vector<size_t> end);
bool blocked3D(Space& space, vector<size_t> start, vector<size_t> end);

bool moveBlocked(Space& space, vector<size_t> start, vector<size_t> end);

#endif // BLOCKED_H