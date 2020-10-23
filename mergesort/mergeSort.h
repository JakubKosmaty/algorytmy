//
// Created by Jakub Kosmaty on 23/10/2020.
//

#ifndef MERGESORT_MERGESORT_HPP
#define MERGESORT_MERGESORT_HPP

#endif //MERGESORT_MERGESORT_HPP

#include <vector>

template<typename T>
void merge(T array[], int start, int end) {
  int a = 0;
  int b = start;
  std::vector<T>tempArray(end - start + 1);
  int mid = (start + end) / 2;
  int c = mid + 1;

  while (b <= mid && c <= end) {
    if (array[b] < array[c]) {
      tempArray[a] = array[b];
      b++;
      a++;
    } else {
      tempArray[a] = array[c];
      c++;
      a++;
    }
  }

  while (b <= mid) {
    tempArray[a] = array[b];
    b++;
    a++;
  }

  while (c <= end) {
    tempArray[a] = array[c];
    c++;
    a++;
  }

  for (int i = start; i <= end; i++) {
    array[i] = tempArray[i - start];
  }
}

template<typename T>
void mergeSort(T array[], int start, int end) {
  if (start < end) {
    int mid = (start + end) / 2;
    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);
    merge(array, start, end);
  }
}

