#include <iostream>
#include <cassert>

#include "PriorityQueue.h"

void testCopyConstructor() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(1,2);

    PriorityQueue<int> stackCopy(priorityQueue);

    assert(stackCopy.top() == priorityQueue.top());
}

void testMoveConstructor() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(1, 2);

    PriorityQueue<int> stackMove(std::move(priorityQueue));

    assert(stackMove.top() == 1);
    assert(priorityQueue.empty());
}

void testCopyAssignment() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(1, 2);

    PriorityQueue<int> stackCopy = priorityQueue;

    assert(stackCopy.top() == priorityQueue.top());
}

void testMoveAssignment() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(1, 2);

    PriorityQueue<int> stackMove = std::move(priorityQueue);

    assert(stackMove.top() == 1);
}

void testEmpty() {
    PriorityQueue<int> priorityQueue;

    assert(priorityQueue.empty());

    priorityQueue.push(4, 10);
    priorityQueue.push(2, 2);
    priorityQueue.push(1, 1);

    assert(!priorityQueue.empty());
}

void testSize() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(4, 10);
    priorityQueue.push(2, 2);
    priorityQueue.push(1, 1);

    assert(priorityQueue.size() == 3);
}

void testPush() {
    PriorityQueue<int> priorityQueue;

    int temp = 10;
    priorityQueue.push(temp, 10);
    temp = 4;
    priorityQueue.push(temp, 2);
    temp = 1;
    priorityQueue.push(temp, 1);

    assert(priorityQueue.top() == 10);
}

void testMovePush() {
    PriorityQueue<std::string> priorityQueue;

    std::string testString = "test";

    priorityQueue.push(std::move(testString), 10);

    assert(priorityQueue.top() == "test");
}

void testTop() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(4, 1);
    priorityQueue.push(7, 2);
    priorityQueue.push(3, 10);
    priorityQueue.push(1, 3);

    assert(priorityQueue.top() == 3);
}

void testPop() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(1, 6);
    priorityQueue.push(6, 2);
    priorityQueue.push(3, 2);
    priorityQueue.push(9, 1);
    priorityQueue.push(5, 8);
    priorityQueue.push(2, 3);

    priorityQueue.pop();

    assert(priorityQueue.top() == 1);
}


void testClear() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(3, 2);
    priorityQueue.push(2, 1);
    priorityQueue.push(3, 5);

    priorityQueue.clear();

    assert(priorityQueue.size() == 0);
}

void testDisplay() {
    PriorityQueue<int> priorityQueue;

    priorityQueue.push(3, 2);
    priorityQueue.push(2, 3);
    priorityQueue.push(7, 1);
    priorityQueue.push(9, 8);
    priorityQueue.push(4, 11);

    priorityQueue.display();
}

int main() {
    testCopyConstructor();
    testMoveConstructor();
    testCopyAssignment();
    testMoveAssignment();
    testEmpty();
    testSize();
    testPush();
    testMovePush();
    testTop();
    testPop();
    testClear();
    testDisplay();
    return 0;
}