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
        size_t m_width;
        size_t m_height;
        size_t m_depth;

        vector<vector<vector<Cube>>> cubes; //3D vector of cubes

        bool _isInBounds(vector<size_t> coordinate) const;
        bool _isInBounds(size_t x, size_t y, size_t z) const;

        bool _is1D() const;
        bool _is2D() const;
        bool _is3D() const;

        void _create(size_t width, size_t height, size_t depth);
        void _scale();

        void _setCube(size_t x, size_t y, size_t z, Cube cube);
        Cube& _getCube(size_t x, size_t y, size_t z);

    public:

        Space();
        Space(size_t width);
        Space(size_t width, size_t height);
        Space(size_t width, size_t height, size_t depth);
        ~Space();

        void resize(size_t width);
        void resize(size_t width, size_t height);
        void resize(size_t width, size_t height, size_t depth);

        size_t width() const;
        size_t height() const;
        size_t depth() const;
        size_t size() const;
        vector<size_t> dimentions() const;

        void setCube(size_t x, Cube cube);
        void setCube(size_t x, size_t y, Cube cube);
        void setCube(size_t x, size_t y, size_t z, Cube cube);
        void setCube(vector<size_t> coordinate, Cube cube);

        Cube& getCube(size_t x);
        Cube& getCube(size_t x, size_t y);
        Cube& getCube(size_t x, size_t y, size_t z);
        Cube& getCube(vector<size_t> coordinate);

        bool isEmpty() const;

        Cube& operator()(vector<size_t> coordinate);
        Cube& operator()(size_t x);
        Cube& operator()(size_t x, size_t y);
        Cube& operator()(size_t x, size_t y, size_t z);

        string toString() const;
        friend ostream& operator<<(ostream& os, Space& space);

        bool moveBlocked(vector<size_t> start, vector<size_t> end) const;

};

#endif // SPACE_H