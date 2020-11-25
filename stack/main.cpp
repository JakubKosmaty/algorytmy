#include <iostream>
#include <assert.h>

#include "Stack.h"

void testCopyConstructor() {
  Stack<int> stack;

  stack.push(1);

  Stack<int> stackCopy(stack);

  assert(stackCopy.top() == stack.top());
}

void testMoveConstructor() {
  Stack<int> stack;

  stack.push(1);

  Stack<int> stackMove(std::move(stack));

  assert(stack.size() == 0);
  assert(stackMove.top() == 1);
}

void testCopyAssignment() {
  Stack<int> stack;

  stack.push(1);

  Stack<int> stackCopy = stack;

  assert(stackCopy.top() == stack.top());
}

void testMoveAssignment() {
  Stack<int> stack;

  stack.push(1);

  Stack<int> stackMove = std::move(stack);

  assert(stack.size() == 0);
  assert(stackMove.top() == 1);
}

void testSize() {
  Stack<int> stack;

  stack.push(1);

  assert(stack.size() == 1);
}

void testPush() {
  Stack<int> stack;

  stack.push(1);

  assert(stack.top() == 1);
}

void testMovePush() {
  Stack<std::string> stack;

  std::string testString = "test";

  stack.push(std::move(testString));

  assert(stack.top() == "test");
  assert(testString.empty());
}

void testTop() {
  Stack<int> stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  assert(stack.top() == 3);
}

void testPop() {
  Stack<int> stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  stack.pop();
  stack.pop();

  assert(stack.top() == 1);
}

void testClear() {
  Stack<int> stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  stack.clear();

  assert(stack.size() == 0);
}

void testDisplay() {
  Stack<int> stack;

  stack.push(3);
  stack.push(2);
  stack.push(7);
  stack.push(9);
  stack.push(4);

  stack.display();
}

int main() {
  testCopyConstructor();
  testMoveConstructor();
  testCopyAssignment();
  testMoveAssignment();
  testSize();
  testPush();
  testMovePush();
  testTop();
  testPop();
  testClear();
  testDisplay();
  return 0;
}