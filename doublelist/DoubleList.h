//
// Created by Jakub Kosmaty on 20/11/2020.
//

#ifndef DOUBLELIST_DOUBLELIST_H
#define DOUBLELIST_DOUBLELIST_H

#include <iostream>
#include <cassert>

template <typename T>
struct DoubleNode {
    T value;
    DoubleNode* next;
    DoubleNode* prev;
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode* nptr = nullptr, DoubleNode* pptr = nullptr) : value(item), next(nptr), prev(pptr) {}
    ~DoubleNode() {}
};

template <typename T>
class DoubleList {
    DoubleNode<T>* head;
    DoubleNode<T>* tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList() {
      clear();
    }

    DoubleList(const DoubleList& other) {
      head = nullptr;
      tail = nullptr;
      DoubleNode<T>* current = other.head;
      while (current != nullptr) {
        push_back(current->value);
        current = current->next;
      }
    }

    DoubleList(DoubleList&& other) {
      head = nullptr;
      tail = nullptr;
      DoubleNode<T>* current = other.head;
      while (current != nullptr) {
        push_back(current->value);
        current = current->next;
      }
    }

    DoubleList& operator=(const DoubleList& other) {
      if (this == &other) {
        return *this;
      }

      clear();
      DoubleNode<T>* current = other.head;
      while (current != nullptr) {
        push_back(current->value);
        current = current->next;
      }
      return *this;
    }

    DoubleList& operator=(DoubleList&& other) {
      if (this == &other) {
        return *this;
      }

      clear();
      DoubleNode<T>* current = other.head;
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
      DoubleNode<T>* node = head;
      while (node != nullptr) {
        size++;
        node = node->next;
      }
      return size;
    }

    void push_front(const T& item) {
      if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
      } else {
        head = tail = new DoubleNode<T>(item);
      }
    }

    void push_front(T&& item) {
      if (!empty()) {
        head = new DoubleNode<T>(std::move(item), head);
        head->next->prev = head;
      } else {
        head = tail = new DoubleNode<T>(std::move(item));
      }
    }

    void push_back(const T& item) {
      if (!empty()) {
        tail->next = new DoubleNode<T>(item);
        tail->next->prev = tail;
        tail = tail->next;
      } else {
        head = tail = new DoubleNode<T>(item);
      }
    }

    void push_back(T&& item) {
      if (!empty()) {
        tail->next = new DoubleNode<T>(item);
        tail->next->prev = tail;
        tail = tail->next;
      } else {
        head = tail = new DoubleNode<T>(std::move(item));
      }

    }

    T& front() const {
      return head->value;
    }

    T& back() const {
      return tail->value;
    }

    void pop_front() {
      assert(!empty());
      DoubleNode<T>* node = head;
      if (head == tail) {
        head = tail = nullptr;
      } else {
        head->next->prev = nullptr;
        head = head->next;
      }
      delete node;
    }

    void pop_back() {
      assert(!empty());
      DoubleNode<T>* node = tail;
      if (head == tail) {
        head = tail = nullptr;
      } else {
        tail->prev->next = nullptr;
        tail = tail->prev;
      }
      delete node;
    }

    void clear() {
      for (DoubleNode<T>* node; !empty();) {
        node = head->next;
        delete head;
        head = node;
      }
    }

    void display() {
      DoubleNode<T>* node = head;
      while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->next;
      }
      std::cout << std::endl;
    }

    void display_reversed() {
      DoubleNode<T>* node = tail;
      while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->prev;
      }
      std::cout << std::endl;
    }

    T& operator[](int pos) {
      assert(pos >= 0);
      int index = 0;
      DoubleNode<T>* node = head;
      while (node != nullptr && pos > index) {
        if (index == pos) {
          break;
        }
        node = node->next;
        index++;
      }
      assert(node != nullptr);
      return node->value;
    }

    const T& operator[](int pos) const {
      assert(pos >= 0);
      int index = 0;
      DoubleNode<T>* node = head;
      while (node != nullptr && pos > index) {
        node = node->next;
        index++;
      }

      assert(node != nullptr);
      return node->value;
    }

    int index(const T& item) {
      int index = 0;
      DoubleNode<T>* node = head;
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

#endif //DOUBLELIST_DOUBLELIST_H
