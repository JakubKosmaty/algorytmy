#include <iostream>

#include "RandomBinaryTree.h"

void testCountLeafs() {
  RandomBinaryTree<int> randomBinaryTree;

  randomBinaryTree.insert(2);
  randomBinaryTree.insert(3);
  randomBinaryTree.insert(1);
  randomBinaryTree.insert(6);
  randomBinaryTree.insert(4);

  assert(randomBinaryTree.count_leafs() == 2);
}

void testIterCountLeafs() {
  RandomBinaryTree<int> randomBinaryTree;

  randomBinaryTree.insert(2);
  randomBinaryTree.insert(3);
  randomBinaryTree.insert(1);
  randomBinaryTree.insert(6);
  randomBinaryTree.insert(4);

  assert(randomBinaryTree.iter_count_leafs() == 2);
}

void testFindMax() {
  RandomBinaryTree<int> randomBinaryTree;

  randomBinaryTree.insert(2);
  randomBinaryTree.insert(3);
  randomBinaryTree.insert(1);
  randomBinaryTree.insert(6);
  randomBinaryTree.insert(4);

  assert(randomBinaryTree.find_max() == 6);
}

void testFindMin() {
  RandomBinaryTree<int> randomBinaryTree;

  randomBinaryTree.insert(2);
  randomBinaryTree.insert(3);
  randomBinaryTree.insert(1);
  randomBinaryTree.insert(6);
  randomBinaryTree.insert(4);

  assert(randomBinaryTree.find_min() == 1);
}

void testIterFindMax() {
  RandomBinaryTree<int> randomBinaryTree;

  randomBinaryTree.insert(2);
  randomBinaryTree.insert(3);
  randomBinaryTree.insert(1);
  randomBinaryTree.insert(6);
  randomBinaryTree.insert(4);

  assert(randomBinaryTree.iter_find_max() == 6);
}

void testIterFindMin() {
  RandomBinaryTree<int> randomBinaryTree;

  randomBinaryTree.insert(2);
  randomBinaryTree.insert(3);
  randomBinaryTree.insert(1);
  randomBinaryTree.insert(6);
  randomBinaryTree.insert(4);

  assert(randomBinaryTree.iter_find_min() == 1);
}

int main() {
  testCountLeafs();
  testIterCountLeafs();
  testFindMax();
  testFindMin();
  testIterFindMax();
  testIterFindMin();
  return 0;
}
