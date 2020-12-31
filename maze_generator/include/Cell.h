//
// Created by Jakub Kosmaty on 19/12/2020.
//

#ifndef MAZE_GENERATOR_CELL_H
#define MAZE_GENERATOR_CELL_H

#include <iostream>

#include "ConsoleControls.h"

class Cell {
private:
    int row;
    int col;

    bool walls[4];
    bool visited;

    const int SHIFT = 3;
public:
    Cell(int row, int col);

    void print();

    int getRow() const;
    int getCol() const;

    void setWall(int index, bool value);

    void setVisited(bool value);
    bool isVisited() const;
};

#endif //MAZE_GENERATOR_CELL_H
