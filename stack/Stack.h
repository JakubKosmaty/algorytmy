//
// Created by jakub on 25.11.2020.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <list>

template <typename T>
class Stack {
private:
    std::list<T> stackList;
public:
    Stack() {}

    ~Stack() {
      stackList.clear();
    }

    Stack(const Stack &other) : stackList(other.stackList) {}

    Stack(Stack &&other) : stackList(std::move(other.stackList)) {}

    Stack &operator=(const Stack &other) {
      if (this == &other) {
        return *this;
      }

      stackList = other.stackList;
      return *this;
    }

    Stack &operator=(Stack &&other) {
      if (this == &other) {
        return *this;
      }

      stackList = std::move(other.stackList);
      return *this;
    }

    bool full() const {
      return stackList.size() == stackList.max_size();
    }

    int size() const {
      return stackList.size();
    }

    int max_size() const {
      return stackList.max_size();
    }

    void push(const T &item) {
      stackList.push_back(item);
    }

    void push(T &&item) {
      stackList.push_back(std::move(item));
    }

    T &top() {
      return stackList.back();
    }

    void pop() {
      stackList.pop_back();
    }

    void clear() {
      stackList.clear();
    }

    void display() {
      std::list<int>::iterator it;
      for (it = stackList.begin(); it != stackList.end(); it++) {
        std::cout << " " << *it;
      }
      std::cout << std::endl;
    }
};

#endif //STACK_STACK_H