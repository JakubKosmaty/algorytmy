//
// Created by Jakub Kosmaty on 19/12/2020.
//

#include <Maze.h>

Maze::Maze(int rows, int cols, int delay) {
  this->rows = rows;
  this->cols = cols;
  this->delay = delay;

  cells.resize(rows);
  for (unsigned i = 0; i < cells.size(); ++i) {
    cells[i].resize(cols);
    for (unsigned j = 0; j < cells[i].size(); ++j) {
      cells[i][j] = new Cell(i, j);
    }
  }
}

void Maze::generate() {
  current = cells[randNumber(0, rows - 1)][randNumber(0, cols - 1)];
  std::stack<Cell*> backTrackStack;

  do {
    printMaze();

    if (delay > 0) {
      std::chrono::milliseconds time(delay);
      std::this_thread::sleep_for(time);
    }

    current->setVisited(true);
    Cell* next = getUnVisitedNeighbors();
    if (next != nullptr) {
      next->setVisited(true);
      backTrackStack.push(current);
      removeWalls(next);
      current = next;
    } else {
      current = backTrackStack.top();
      backTrackStack.pop();
    }
  } while (!backTrackStack.empty());

  printMaze(true);
}

// Rand one of unvisited neighbors
Cell* Maze::getUnVisitedNeighbors() {
  std::vector<Cell*> neighbors;

  int currentCol = current->getCol();
  int currentRow = current->getRow();

  std::pair<int, int> dir[4] = {
    std::make_pair(0, 1),
    std::make_pair(0, -1),
    std::make_pair(1, 0),
    std::make_pair(-1, 0),
  };

  for (auto & p : dir) {
    int tempCol = currentCol + p.first;
    int tempRow = currentRow + p.second;

    if(isColValid(tempCol) && isRowValid(tempRow) && !cells[tempRow][tempCol]->isVisited()) {
      neighbors.push_back(cells[tempRow][tempCol]);
    }
  }

  if (!neighbors.empty()) {
    return neighbors[randNumber(0, neighbors.size() - 1)];
  }

  return nullptr;
}

bool Maze::isColValid(int index) const {
  return (index >= 0 && index < cols);
}

bool Maze::isRowValid(int index) const {
  return (index >= 0 && index < rows);
}

int Maze::randNumber(int from, int to) const {
  std::random_device rd;
  std::mt19937::result_type seed = rd() ^ (
      (std::mt19937::result_type)
          std::chrono::duration_cast<std::chrono::seconds>(
              std::chrono::system_clock::now().time_since_epoch()
          ).count() +
      (std::mt19937::result_type)
          std::chrono::duration_cast<std::chrono::microseconds>(
              std::chrono::high_resolution_clock::now().time_since_epoch()
          ).count() );

  std::mt19937 gen(seed);
  std::uniform_int_distribution<unsigned> distrib(from, to);
  return distrib(gen);
}

// Remove walls between current and next
void Maze::removeWalls(Cell *next) {
  int currentRow = current->getRow();
  int currentCol = current->getCol();
  int nextRow = next->getRow();
  int nextCol = next->getCol();

  if(currentCol == nextCol && currentRow == nextRow + 1) {
    current->setWall(TOP, false);
    next->setWall(BOTTOM, false);
  }

  if(currentCol == nextCol && currentRow == nextRow - 1) {
    current->setWall(BOTTOM, false);
    next->setWall(TOP, false);
  }

  if(currentCol == nextCol + 1 && currentRow == nextRow) {
    current->setWall(LEFT, false);
    next->setWall(RIGHT, false);
  }

  if(currentCol == nextCol - 1 && currentRow == nextRow) {
    current->setWall(RIGHT, false);
    next->setWall(LEFT, false);
  }
}

void Maze::printMaze(bool last) const {
  CONSOLE_CLEAR;
  CONSOLE_POS(1, 1);

  if (last) {
    CONSOLE_COLOR_TEXT(CYAN, "Finish!");
  } else {
    CONSOLE_COLOR_TEXT(GREEN, "Maze generating...");
  }

  for (auto & cell : cells) {
    for (auto j : cell) {
      j->print();
    }
  }

  if (!last) {
    CONSOLE_POS(current->getRow() + 1 + 3, current->getCol() + 2 + current->getCol() + 3);
    CONSOLE_COLOR_TEXT(MAGENTA, "#");
  }

  printf("\n\n");
  fflush(stdout);
}

Maze::~Maze() {
  for (auto & cell : cells) {
    for (auto & j : cell) {
      delete j;
    }
  }
}
