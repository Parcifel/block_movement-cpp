# Blocked Movement

> #### This project was inspired by a game I coded in university.
> The idea was that a piece can moveing on a 2D tiles plane can be blocked by walls. There are different ways of blocking the piece and the pieces could only move in certain directions.
> This project is an extention of that problem to a 3d space of cubes.
> I will also adapt this project to be able to work with a 2D plane of cubes and a 1D line of cubes.


## Background

The original game was a 2D game where the player could move a piece around a 2D plane of tiles. 
The pieces would move in a straight line or in a diagonal line.
Walls could block the pieces from moving in a certain direction.

A piece would be considered block vertically/horizontally if there was a wall in the same row/column as the piece.

A piece would be considered block diagonally if there are 2 walls in one of 4 possible positions:
1. When the starting tile is blocked off by an L shape of walls.
2. When the ending tile is blocked off by an L shape of walls.
3. When a long vertical wall is blocking the piece from moving diagonally.
4. When a long horizontal wall is blocking the piece from moving diagonally.

## Original solution

In my original implementation I solved this problem using recursion.

> **Base Case:**
> 
> If the movement of the piece is in one dimention (either vertical or horizontal) then the piece is blocked if there is a wall in the same row/column as the piece.

> **Recursive:**
>
> ST -> Starting Tile
> ET -> Ending Tile
>
> Firstly I got 2 other tiles:
>   - Column Tile(CT): The tile is the came column as the ending tile
>   - Row Tile(RT): The tile is the same row as the ending tile
> Secondly I decomposed the movement into 2 1D moves and checked if they were blocked by walls.
>  1. ST -> CT  && ST -> RT  (starting tile is blocked)  
>  2. ET -> CT  && ET -> RT  (ending tile is blocked)
>  3. ST -> CT  && ET -> RT  (long vertical wall is blocking)
>  4. ST -> RT  && ET -> FT  (long horizontal wall is blocking)


## Scope of this project

This project will implement the original solution in 3D space.
The project will also implement the solution for 2D and 1D space.

The project will have 2 classes that will be used to solve the problem:
1. Space  -> The space that the pieces will be moving in.
2. Cube   -> The "tiles" that the pieces will be moving on.

**NOTE:** This project will not implement any pieces that will be moving on the space. This project will only implement the space and the tiles that the pieces will be moving on.

