//
// Created by Jakub Kosmaty on 19/12/2020.
//

#ifndef MAZE_GENERATOR_MAZE_H
#define MAZE_GENERATOR_MAZE_H

#include <thread>
#include <vector>
#include <ctime>
#include <random>
#include <stack>

#include "Cell.h"

class Maze {
private:
    int rows;
    int cols;
    int delay;

    std::vector<std::vector<Cell*>> cells;
    Cell* current;

    Cell* getUnVisitedNeighbors();

    void removeWalls(Cell* next);

    bool isColValid(int index) const;
    bool isRowValid(int index) const;

    int randNumber(int from, int to) const;

    void printMaze(bool last = false) const;
public:
    Maze(int rows, int cols, int delay);
    virtual ~Maze();

    void generate();
};

#endif //MAZE_GENERATOR_MAZE_H
