/**
 * This class represents a cube.
 * 3 Faces of the cube can be colored.
 * The front, the bottom, and the side.
*/
#ifndef CUBE_H
#define CUBE_H

#include <string>
using namespace std;

class Cube {
    private:
        bool side;
        bool front;
        bool bottom;

    public:
        Cube();
        Cube(bool side, bool front, bool bottom);
        ~Cube();

        void setSide(bool side=true);
        void setFront(bool front=true);
        void setBottom(bool bottom=true);

        void unsetSide();
        void unsetFront();
        void unsetBottom();

        bool hasSide() const;
        bool hasFront() const;
        bool hasBottom() const;

        string toString();
};

#endif // CUBE_H
