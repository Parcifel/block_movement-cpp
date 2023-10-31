/**
 * This class represents a 3D space.
 * It is comprised of cubes.
*/
// TODO: Write this into being able to be just a 2D space or even a 1D space
#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <vector>
#include "cube.h"

using namespace std;   

class Space {
    private:
        size_t width;
        size_t height;
        size_t depth;

        vector<vector<vector<Cube>>> cubes; //3D vector of cubes

        bool _isInBounds(size_t x, size_t y, size_t z) const;
        bool _is3D(vector<size_t> coordinate) const;
        void _scale();

    public:

        Space();
        Space(size_t width, size_t height, size_t depth);
        ~Space();

        void setWidth(size_t width);
        void setHeight(size_t height);
        void setDepth(size_t depth);

        size_t getWidth() const;
        size_t getHeight() const;
        size_t getDepth() const;

        void setCube(size_t x, size_t y, size_t z, Cube cube);
        void setCube(vector<size_t> coordinate, Cube cube);
        Cube& getCube(size_t x, size_t y, size_t z);
        Cube& getCube(vector<size_t> coordinate);

        bool moveBlocked(vector<size_t> start, vector<size_t> end) const;

        bool isEmpty() const;

};

#endif // SPACE_H