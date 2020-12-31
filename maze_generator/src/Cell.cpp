//
// Created by Jakub Kosmaty on 19/12/2020.
//

#include "Cell.h"

Cell::Cell(int row, int col) : walls{true, true, true, true}, visited(false) {
  this->row = row;
  this->col = col;
}

void Cell::print() {
  if (walls[0]) {
    CONSOLE_POS(row + SHIFT, col * 2 + 2 + SHIFT);
    CONSOLE_COLOR_TEXT(RED, "_");
  }

  if (walls[1]) {
    CONSOLE_POS(row + 1 + SHIFT, col * 2 + 3 + SHIFT);
    CONSOLE_COLOR_TEXT(RED, "|");
  }

  if (walls[2]) {
    CONSOLE_POS(row + 1 + SHIFT, col * 2 + 2 + SHIFT);
    CONSOLE_COLOR_TEXT(RED, "_");
  }

  if (walls[3]) {
    CONSOLE_POS(row + 1 + SHIFT, col * 2 + 1 + SHIFT);
    CONSOLE_COLOR_TEXT(RED, "|");
  }
}

int Cell::getRow() const {
  return row;
}

int Cell::getCol() const {
  return col;
}

void Cell::setWall(int index, bool value) {
  walls[index] = value;
}

void Cell::setVisited(bool value) {
  visited = value;
}

bool Cell::isVisited() const {
  return visited;
}
