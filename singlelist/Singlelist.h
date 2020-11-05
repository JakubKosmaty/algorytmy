//
// Created by Jakub Kosmaty on 04/11/2020.
//

#ifndef SINGLELIST_SINGLELIST_H
#define SINGLELIST_SINGLELIST_H

#include <iostream>
#include <cassert>

template <typename T>
struct SingleNode {
    T value;
    SingleNode* next;
    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, SingleNode* ptr = nullptr) : value(item), next(ptr) {}
    ~SingleNode() {}
};

template <typename T>
class SingleList {
private:
    SingleNode<T>* head;
    SingleNode<T>* tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList() {
      clear();
    }

    SingleList(const SingleList<T>& other) {
      head = nullptr;
      tail = nullptr;
      SingleNode<T>* current = other.head;
      while (current != nullptr) {
        push_back(current->value);
        current = current->next;
      }
    }

    SingleList<T>& operator=(const SingleList<T>& other) {
      if (this == &other) {
        return *this;
      }

      clear();
      SingleNode<T>* current = other.head;
      while (current != nullptr) {
        push_back(current->value);
        current = current->next;
      }
      return *this;
    }

    bool empty() const {
      return head == nullptr;
    }

    int size() const {
      int size = 0;
      SingleNode<T>* node = head;
      while (node != nullptr) {
        size++;
        node = node->next;
      }
      return size;
    }

    void push_front(const T& item) {
      if (!empty()) {
        head = new SingleNode<T>(item, head);
      } else {
        head = tail = new SingleNode<T>(item);
      }
    }

    void push_back(const T& item) {
      if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
      } else {
        head = tail = new SingleNode<T>(item);
      }
    }

    T& front() const {
      return head->value;
    }

    T& back() const {
      return tail->value;
    }

    void pop_front() {
      SingleNode<T>* node = head;
      if (head == tail) {
        head = tail = nullptr;
      } else {
        head = head->next;
      }
      delete node;
    }

    void pop_back() {
      SingleNode<T>* node = tail;
      if (head == tail) {
        head = tail = nullptr;
      } else {
        SingleNode<T>* before = head;
        while (before->next != tail) {
          before = before->next;
        }
        tail = before;
        tail->next = nullptr;
      }
      delete node;
    }

    void clear() {
      for (SingleNode<T>* node; !empty();) {
        node = head->next;
        delete head;
        head = node;
      }
    }

    void display(){
      SingleNode<T>* node = head;
      while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->next;
      }
      std::cout << std::endl;
    }

    void reverse() {
      SingleNode<T>* current = head;
      SingleNode<T>* next = nullptr;
      SingleNode<T>* prev = nullptr;
      while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      }
      head = prev;
    }

    const T& operator[](int pos) const {
      assert(pos >= 0);
      int index = 0;
      SingleNode<T>* node = head;
      while (node != nullptr && pos > index){
        node = node->next;
        index++;
      }

      assert(node != nullptr);
      return node->value;
    }

    int index(const T& item) {
      int index = 0;
      SingleNode<T>* node = head;
      while (node != nullptr){
        if (node->value == item) {
          return index;
        }
        node = node->next;
        index++;
      }
      return -1;
    }
};

#endif //SINGLELIST_SINGLELIST_H
