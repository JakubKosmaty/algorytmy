#include <iostream>

#include "DoubleList.h"

void testPushFront() {
  DoubleList<int> doubleList;
  doubleList.push_front(2);
  doubleList.push_front(5);
  doubleList.push_front(7);

  assert(doubleList[0] == 7);
  assert(doubleList[1] == 5);
  assert(doubleList[2] == 2);
}

void testPushBack() {
  DoubleList<int> doubleList;
  doubleList.push_back(2);
  doubleList.push_back(5);
  doubleList.push_back(4);

  assert(doubleList[0] == 2);
  assert(doubleList[1] == 5);
  assert(doubleList[2] == 4);
}

void testEmpty() {
  DoubleList<float> doubleList;

  assert(doubleList.empty());

  doubleList.push_front(2.4);

  assert(!doubleList.empty());
}

void testFrontAndBack() {
  DoubleList<char> doubleList;
  doubleList.push_back('s');
  doubleList.push_back('d');
  doubleList.push_back('c');
  doubleList.push_back('a');
  doubleList.push_back('t');

  assert(doubleList.front() == 's');
  assert(doubleList.back() == 't');
}

void testPopFront() {
  DoubleList<char> doubleList;
  doubleList.push_back('s');
  doubleList.push_back('d');
  doubleList.push_back('c');
  doubleList.push_back('a');
  doubleList.push_back('t');

  doubleList.pop_front();
  assert(doubleList[0] == 'd');
}

void testPopBack() {
  DoubleList<char> doubleList;
  doubleList.push_back('s');
  doubleList.push_back('d');
  doubleList.push_back('c');
  doubleList.push_back('a');
  doubleList.push_back('t');

  doubleList.pop_back();
  assert(doubleList[doubleList.size() - 1] == 'a');
}

void testClear() {
  DoubleList<int> doubleList;
  doubleList.push_front(2);
  doubleList.clear();
  assert(doubleList.empty());
}

void testIndex() {
  DoubleList<char> doubleList;

  doubleList.push_back('s');
  doubleList.push_back('d');
  doubleList.push_back('c');

  doubleList[0] = '1';
  doubleList[1] = '2';
  doubleList[2] = 'd';

  assert(doubleList.index('d') == 2);
  assert(doubleList.index('u') == -1);
}

void testOperatorOver() {
  DoubleList<char> doubleList;
  doubleList.push_back('s');
  doubleList.push_back('d');
  doubleList.push_back('c');
  doubleList.push_back('a');
  doubleList.push_back('t');

  assert(doubleList[0] == 's');
  assert(doubleList[1] == 'd');
  assert(doubleList[2] == 'c');
  assert(doubleList[3] == 'a');
  assert(doubleList[4] == 't');
}

void testSize() {
  DoubleList<std::string> doubleList;

  for (int i = 0; i < 50; ++i) {
    doubleList.push_back("d");
  }
  assert(doubleList.size() == 50);
}

void testDisplayAndReversed() {

  DoubleList<char> doubleList;
  doubleList.push_back('a');
  doubleList.push_back('b');
  doubleList.push_back('c');
  doubleList.push_back('d');

  doubleList.display();
  doubleList.display_reversed();
}

void testOperators() {
  DoubleList<char> doubleList;
  doubleList.push_back('a');
  doubleList.push_back('b');
  doubleList.push_back('c');
  doubleList.push_back('d');

  DoubleList<char> copyList = doubleList;

  DoubleList<char> copyList2(doubleList);

  for (int i = 0; i < copyList.size(); ++i) {
    assert(copyList[i] == doubleList[i]);
    assert(copyList2[i] == doubleList[i]);
  }
}

int main() {
  testPushFront();
  testPushBack();
  testEmpty();
  testFrontAndBack();
  testPopFront();
  testPopBack();
  testClear();
  testIndex();
  testOperatorOver();
  testSize();
  testDisplayAndReversed();
  testOperators();
  return 0;
}