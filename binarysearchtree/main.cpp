#include <iostream>

#include "BinarySearchTree.h"

void testfindMax() {
  BinarySearchTree<int> binarySearchTree;
  binarySearchTree.insert(10);
  binarySearchTree.insert(2);
  binarySearchTree.insert(3);
  binarySearchTree.insert(5);
  binarySearchTree.insert(12);
  binarySearchTree.insert(33);

  assert(binarySearchTree.find_max() == 33);
}

void testfindMin() {
  BinarySearchTree<int> binarySearchTree;
  binarySearchTree.insert(10);
  binarySearchTree.insert(2);
  binarySearchTree.insert(3);
  binarySearchTree.insert(5);
  binarySearchTree.insert(12);
  binarySearchTree.insert(33);

  assert(binarySearchTree.find_min() == 2);
}

void testisBST() {
  BinarySearchTree<int> binarySearchTree;
  binarySearchTree.insert(10);
  binarySearchTree.insert(2);
  binarySearchTree.insert(1);
  binarySearchTree.insert(7);
  binarySearchTree.insert(3);

  assert(binarySearchTree.isBST());
}

int main() {
  testfindMax();
  testfindMin();
  testisBST();
  return 0;
}
