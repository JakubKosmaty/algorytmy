#include <iostream>
#include "SingleList.h"

void testPushFront() {
  SingleList<int> singleList;
  singleList.push_front(2);
  singleList.push_front(5);
  singleList.push_front(7);

  assert(singleList[0] == 7);
  assert(singleList[1] == 5);
  assert(singleList[2] == 2);
}

void testPushBack() {
  SingleList<int> singleList;
  singleList.push_back(2);
  singleList.push_back(5);
  singleList.push_back(4);

  assert(singleList[0] == 2);
  assert(singleList[1] == 5);
  assert(singleList[2] == 4);
}

void testEmpty() {
  SingleList<float> singleList;

  assert(singleList.empty());

  singleList.push_front(2.4);

  assert(!singleList.empty());
}

void testFrontAndBack() {
  SingleList<char> singleList;
  singleList.push_back('s');
  singleList.push_back('d');
  singleList.push_back('c');
  singleList.push_back('a');
  singleList.push_back('t');

  assert(singleList.front() == 's');
  assert(singleList.back() == 't');
}

void testPopFront() {
  SingleList<char> singleList;
  singleList.push_back('s');
  singleList.push_back('d');
  singleList.push_back('c');
  singleList.push_back('a');
  singleList.push_back('t');

  singleList.pop_front();
  assert(singleList[0] == 'd');
}

void testPopBack() {
  SingleList<char> singleList;
  singleList.push_back('s');
  singleList.push_back('d');
  singleList.push_back('c');
  singleList.push_back('a');
  singleList.push_back('t');

  singleList.pop_back();
  assert(singleList[singleList.size() - 1] == 'a');
}

void testClear() {
  SingleList<int> singleList;
  singleList.push_front(2);
  singleList.clear();
  assert(singleList.empty());
}

void testReverse() {
  SingleList<char> singleList;
  singleList.push_back('s');
  singleList.push_back('d');
  singleList.push_back('c');
  singleList.push_back('a');
  singleList.push_back('t');

  SingleList<char> temp = singleList;
  singleList.reverse();

  for (int i = 0; i < singleList.size(); i++) {
    assert(singleList[i] == temp[temp.size() - 1 - i]);
  }

  singleList.display();
  temp.display();
}

void testIndex() {
  SingleList<char> singleList;
  singleList.push_back('s');
  singleList.push_back('d');
  singleList.push_back('c');
  singleList.push_back('a');
  singleList.push_back('t');

  assert(singleList.index('c') == 2);
}

void testOperatorOver() {
  SingleList<char> singleList;
  singleList.push_back('s');
  singleList.push_back('d');
  singleList.push_back('c');
  singleList.push_back('a');
  singleList.push_back('t');

  assert(singleList[0] == 's');
  assert(singleList[1] == 'd');
  assert(singleList[2] == 'c');
  assert(singleList[3] == 'a');
  assert(singleList[4] == 't');
}

void testSize() {
  SingleList<std::string> singleList;

  for (int i = 0; i < 50; ++i) {
    singleList.push_back("d");
  }
  assert(singleList.size() == 50);
}

int main() {
  testPushFront();
  testPushBack();
  testEmpty();
  testFrontAndBack();
  testPopFront();
  testPopBack();
  testClear();
  testReverse();
  testIndex();
  testOperatorOver();
  testSize();
  return 0;
}
