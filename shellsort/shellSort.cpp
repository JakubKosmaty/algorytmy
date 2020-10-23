//
// Created by Jakub Kosmaty on 23/10/2020.
//

int shellSort(int array[], int size) {
  for (int gap = size/2; gap > 0; gap /= 2) {
    for (int i = gap; i < size; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
        array[j] = array[j - gap];
      }

      array[j] = temp;
    }
  }
  return 0;
}

