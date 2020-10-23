#include <iostream>

#include "mergeSort.h"

template<typename T>
void printArray(T array[], int size) {
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

  mergeSort(array, 0, size - 1);
  printArray(array, size);
  return 0;
}
