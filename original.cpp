/**
 * This is the original algorithm for the problem.
 * 
 * This was translated from python code.
 * It also uses different classes than what I am using in this project
*/

#include <vector>
#include <cassert>
#include <cmath>

using namespace std;


class Tile {
    private:
        bool west_wall;
        bool south_wall;

    public:
        Tile(bool west_wall, bool south_wall) {
            this->west_wall = west_wall;
            this->south_wall = south_wall;
        }

        bool hasWestWall() {
            return this->west_wall;
        }
        bool hasSouthWall() {
            return this->south_wall;
        }
};

class Board {
    private:
        vector<vector<Tile>> tiles;
        size_t size;

        void _scale() {
            if (tiles.size() == 0) {
                return;
            }

            tiles.resize(size);
            for (size_t i = 0; i < size; i++) {
                tiles[i].resize(size);
            }

        }

        bool _outOfBound(vector<size_t> coord) const {
            assert(coord.size() == 2);
            size_t x = coord[0];
            size_t y = coord[1];

            return (x < 0 || x >= size || y < 0 || y >= size);
        }

    public:
        Board(size_t size) {
            this->size = size;
            this->_scale();
        }

        bool blockedByWall(vector<size_t> start_coord, vector<size_t> end_coord) const {
            /**
             * This is the function that will calculate if a piece can move from one square to an adjasent square
            */
            assert(start_coord.size() == 2);
            assert(end_coord.size() == 2);

            assert(!this->_outOfBound(start_coord));
            assert(!this->_outOfBound(end_coord));

            size_t x1 = start_coord[0];
            size_t y1 = start_coord[1];
            size_t x2 = end_coord[0];
            size_t y2 = end_coord[1];

            int x_diff = x2 - x1;
            int y_diff = y2 - y1;

            Tile start_tile = tiles[x1][y1];
            Tile end_tile = tiles[x2][y2];

            if ((x_diff == 0) || (y_diff == 0)) {
                if (x_diff == 0) {
                    if (y_diff == 1) {
                        return end_tile.hasWestWall();
                    } else if (y_diff == -1) {
                        return start_tile.hasWestWall();
                    }
                } else if  (y_diff == 0) {
                    if (x_diff == 1) {
                        return start_tile.hasSouthWall();
                    } else if (x_diff == -1) {
                        return end_tile.hasSouthWall();
                    }
                }
            } else {
                vector<size_t> row_coord = {x1 + x_diff, y1};
                vector<size_t> col_coord = {x2, y2 + y_diff};

                if (this->blockedByWall(start_coord, col_coord) && this->blockedByWall(start_coord, row_coord)) {
                    return true;
                } else if (this->blockedByWall(end_coord, col_coord) && this->blockedByWall(end_coord, row_coord)) {
                    return true;
                } else if (this->blockedByWall(start_coord, col_coord) && this->blockedByWall(end_coord, row_coord)) {
                    return true;
                } else if (this->blockedByWall(start_coord, row_coord) && this->blockedByWall(end_coord, col_coord)) {
                    return true;
                }
            }
            return false;
        }

};
