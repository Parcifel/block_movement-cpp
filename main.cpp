/**
 * This project was inspired by a problem I solved in a chess project.
 * 
 * The original problem was that pieces moving could be blocked by walls.
 * Walls can be placed on the south side of a tile or on the west side of a tile.
 * Because pieces can use in a 2D space, my solution used recursion to decompose a 2D movement in to 2 1D movements.
 * Then it would check if the 1D movement was blocked by a wall.
 * 
 * Originally there was 4 different 1D movements:
 *   - Vertival up and down
 *   - Horizontal left and right
 * There was also 4 ways a 2D movement could be blocked:
 *   - Block the starting tile off
 *   - Block the ending tile off
 *   - 2 south walls
 *   - 2 west walls
 * 
 * This program will expand this implementation to a 3d space.
 * NOTE: There are 2 different implementations in this project. 
 *  1. Checking a simple movement, i.e. max of 1 in each direction
 *  2. Decompose an entire movement into smaller moves
 * 
*/
#include <iostream>

#include "space.h"
#include "cube.h"
#include "blocked.h"

using namespace std;


int main() {

    // Space space(3, 3, 3);

    // space.setCube(0, 0, 0, Cube(true, false, false));
    // space.setCube(0, 0, 1, Cube(true, true, false));
    // space.setCube(0, 0, 2, Cube(true, false, true));
    // space.setCube(0, 1, 0, Cube(false, true, false));

    // cout << "Space size: " << space.getWidth() << "x" << space.getHeight() << "x" << space.getDepth() << endl;
    // cout << "Space is empty: " << space.isEmpty() << endl;
    // cout << "Cube at (0, 1, 0): " << space.getCube(0, 1, 0).toString() << endl;

    // cout << "Resizing ..." << endl;
    // space.setWidth(4);
    // space.setHeight(5);
    // space.setDepth(6);

    // cout << "Space size: " << space.getWidth() << "x" << space.getHeight() << "x" << space.getDepth() << endl;
    // cout << "Space is empty: " << space.isEmpty() << endl;
    // cout << "Cube at (0, 1, 0): " << space.getCube(0, 1, 0).toString() << endl;
    // cout << "Cube at (4, 5, 6): " << space.getCube(3, 4, 5).toString() << endl;

    Space space(3, 3, 3);

    Cube cube000(false, true, false);
    vector<size_t> vect000 = {0, 0, 0};

    Cube cube100(true, false, false);
    vector<size_t> vect100 = {1, 0, 0};

    Cube cube001(false, true, false);
    vector<size_t> vect001 = {0, 0, 1};

    Cube cube101(true, true, false);
    vector<size_t> vect101 = {1, 0, 1};

    Cube cube002(false, true, true);
    vector<size_t> vect002 = {0, 0, 2};

    Cube cube011(false, false, true);
    vector<size_t> vect011 = {0, 1, 1};

    Cube cube111(false, true, true);
    vector<size_t> vect111 = {1, 1, 1};

    Cube cube211(false, true, false);
    vector<size_t> vect211 = {2, 1, 1};

    Cube cube012(false, true, false);
    vector<size_t> vect012 = {0, 1, 2};

    Cube cube112(false, false, true);
    vector<size_t> vect112 = {1, 1, 2};

    Cube cube121(false, true, false);
    vector<size_t> vect121 = {1, 2, 1};

    Cube cube221(false, true, false);
    vector<size_t> vect221 = {2, 2, 1};

    Cube cube222(false, false, true);
    vector<size_t> vect222 = {2, 2, 2};

    space.setCube(vect000, cube000);
    space.setCube(vect100, cube100);
    space.setCube(vect001, cube001);
    space.setCube(vect101, cube101);
    space.setCube(vect002, cube002);
    space.setCube(vect011, cube011);
    space.setCube(vect111, cube111);
    space.setCube(vect211, cube211);
    space.setCube(vect012, cube012);
    space.setCube(vect112, cube112);
    space.setCube(vect121, cube121);
    space.setCube(vect221, cube221);
    space.setCube(vect222, cube222);

    Cube cube1(true, false, false);
    Cube cube2(false, true, false);
    Cube cube3(false, false, true);
    Cube cube4(true, true, false);
    Cube cube5(true, false, true);
    Cube cube6(false, true, true);
    Cube cube7(true, true, true);

    vector<size_t> vect1 = {0, 0, 0};
    vector<size_t> vect2 = {1, 0, 0};
    vector<size_t> vect3 = {0, 1, 0};
    vector<size_t> vect4 = {0, 0, 1};

    cout << "Cube 1: " << cube1.toString() << endl;
    cout << "Cube 2: " << cube2.toString() << endl;
    cout << "Cube 3: " << cube3.toString() << endl;
    cout << "Cube 4: " << cube4.toString() << endl;
    cout << "Cube 5: " << cube5.toString() << endl;
    cout << "Cube 6: " << cube6.toString() << endl;
    cout << "Cube 7: " << cube7.toString() << endl;
    cout << endl;

    cout << "Exp: True -- " << blockedInUnitX(cube1, cube2, -1) << endl;  
    cout << "Exp: False -- " << blockedInUnitX(cube1, cube3, 1) << endl;
    cout << "Exp: True -- " << blockedInUnitY(cube1, cube3, 1) << endl;
    cout << "Exp: False -- " << blockedInUnitY(cube1, cube2, -1) << endl;
    cout << "Exp: True -- " << blockedInUnitZ(cube1, cube4, 1) << endl;
    cout << "Exp: False -- " << blockedInUnitZ(cube1, cube2, -1) << endl;
    cout << endl;

    cout << "Exp: True -- " << is1DMove(vect1, vect2) << endl;
    cout << "Exp: True -- " << is1DMove(vect1, vect3) << endl;
    cout << "Exp: True -- " << is1DMove(vect1, vect4) << endl;
    cout << "Exp: False -- " << is1DMove(vect1, vect1) << endl;
    cout << "Exp: False -- " << is1DMove(vect2, vect3) << endl;
    cout << "Exp: False -- " << is1DMove(vect2, vect4) << endl;
    cout << endl;

    cout << "1D Moves" << endl;
    cout << "Exp True == " << blocked1D(space, vect000, vect100) << endl;
    cout << "Exp False == " << blocked1D(space, vect111, vect121) << endl;
    cout << "Exp False == " << blocked1D(space, vect111, vect211) << endl;
    cout << "Exp True == " << blocked1D(space, vect001, vect101) << endl;
    cout << "Exp True == " << blocked1D(space, vect001, vect002) << endl;

    cout << "Done!" << endl;

    return 0;

}