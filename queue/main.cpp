#include <iostream>
#include <assert.h>

#include "MyQueue.h"

void testCopyConstructor() {
    MyQueue<int> myQueue;

    myQueue.push(1);

    MyQueue<int> stackCopy(myQueue);

    assert(stackCopy.front() == myQueue.front());
}

void testMoveConstructor() {
    MyQueue<int> myQueue;

    myQueue.push(1);

    MyQueue<int> stackMove(std::move(myQueue));

    assert(stackMove.front() == 1);
}

void testCopyAssignment() {
    MyQueue<int> myQueue;

    myQueue.push(1);

    MyQueue<int> stackCopy = myQueue;

    assert(stackCopy.front() == myQueue.front());
}

void testMoveAssignment() {
    MyQueue<int> myQueue;

    myQueue.push(1);

    MyQueue<int> stackMove = std::move(myQueue);

    assert(stackMove.front() == 1);
}

void testEmpty() {
    MyQueue<int> myQueue;

    assert(myQueue.empty());

    myQueue.push(1);

    assert(!myQueue.empty());
}

void testFull() {
    MyQueue<int> myQueue(2);

    myQueue.push(1);
    myQueue.push(2);

    assert(myQueue.full());
}

void testSize() {
    MyQueue<int> myQueue;

    myQueue.push(1);

    assert(myQueue.size() == 1);
}

void testPush() {
    MyQueue<int> myQueue;

    myQueue.push(1);

    assert(myQueue.front() == 1);
}

void testMovePush() {
    MyQueue<std::string> myQueue;

    std::string testString = "test";

    myQueue.push(std::move(testString));

    assert(myQueue.front() == "test");
    assert(testString.empty());
}

void testFront() {
    MyQueue<int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    assert(myQueue.front() == 1);
}

void testBack() {
    MyQueue<int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    assert(myQueue.back() == 3);
}

void testPop() {
    MyQueue<int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    myQueue.pop();
    myQueue.pop();

    assert(myQueue.front() == 3);
}

void testClear() {
    MyQueue<int> myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    myQueue.clear();

    assert(myQueue.size() == 0);
}

void testDisplay() {
    MyQueue<int> myQueue;

    myQueue.push(3);
    myQueue.push(2);
    myQueue.push(7);
    myQueue.push(9);
    myQueue.push(4);

    myQueue.display();
}

int main() {
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignment();
    testMoveAssignment();
    testEmpty();
    testFull();
    testSize();
    testPush();
    testMovePush();
    testFront();
    testBack();
    testPop();
    testClear();
    testDisplay();
    return 0;
}
