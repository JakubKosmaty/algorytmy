#include "Maze.h"

int main() {
  int rows;
  int cols;
  CONSOLE_CLEAR;
  CONSOLE_POS(1, 1);
  CONSOLE_COLOR_TEXT(BLUE, "Enter the size of the maze: <rows, cols>\n");
  std::cin >> rows >> cols;

  int delay = 0;
  CONSOLE_POS(4, 1);
  CONSOLE_COLOR_TEXT(BLUE, "Enter the generation delay: <ms>\n");
  std::cin >> delay;

  Maze maze(rows, cols, delay);
  maze.generate();
  return 0;
}