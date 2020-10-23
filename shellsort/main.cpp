#include <iostream>
#include <cstdlib>
#include <ctime>

#include "shellSort.h"

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++ ) {
    std::cout << array[i] << std::endl;
  }
}

int main() {
  int size = 0;
  std::cout << "Podaj wielkosc tablicy:" << std::endl;
  std::cin >> size;

  int array[size];
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }

  shellSort(array, size);
  printArray(array, size);
  return 0;
}
