//
// Created by Jakub Kosmaty on 29/10/2020.
//

#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <cassert>
#include <algorithm>

const int GROWTH = 2;
const int MIN_SIZE = 2;

template<typename T>
class ArrayList {
private:
    T*  array;
    int capacity;
    int m_size;

    void initArray() {
      array = new T[capacity];
      assert(array != nullptr);
      m_size = 0;
    }

    void resize() {
      capacity *= GROWTH;
      T* tempArray = new T[capacity];

      for (int i = 0; i < m_size; ++i) {
        tempArray[i] = array[i];
      }

      delete[] array;
      array = tempArray;
    }
public:
    ArrayList() : capacity(MIN_SIZE) {
      initArray();
    }

    virtual ~ArrayList() {
      delete[] array;
    }

    ArrayList(const ArrayList<T>& other) {
      copyArray(other);
    }

    ArrayList& operator=(const ArrayList<T>& other) {
      return copyArray(other);
    }

    ArrayList& copyArray(const ArrayList<T>& other) {
      if (array == other.array) {
        return *this;
      }

      array = new T[other.capacity];
      assert(array != nullptr);

      for (int i = 0; i < other.size(); i++) {
        array[i] = other.array[i];
      }

      m_size = other.size();
      capacity = other.capacity;

      return *this;
    }

    void push_front(const T& item) {
      insert(item, 0);
    }

    void push_back(const T& item) {
      insert(item, m_size);
    }

    void pop_front() {
      remove(0);
    }

    void pop_back() {
      remove(m_size - 1);
    }

    void clear() {
      delete[] array;
      initArray();
    }

    int index(const T& item) const {
      for (int i = 0; i < m_size; i++) {
        if (array[i] == item) {
          return i;
        }
      }
      return -1;
    }

    T& front() const {
      return array[0];
    }

    T& back() const {
      return array[m_size - 1];
    }

    bool empty() const {
      return m_size == 0;
    };

    int size() const {
      return m_size;
    }

    void reverse() const {
      std::reverse(array, array + m_size);
    }

    void sort() const {
      std::sort(array, array + m_size);
    }

    void merge(ArrayList<T>& other) {
      for (int i = 0; i < other.m_size; i++) {
        insert(other.array[i], m_size);
      }
    }

    T& operator[](int index) {
      assert(index >= 0 && index < m_size);
      return array[index];
    }

    const T& operator[](int index) const {
      assert(index >= 0 && index < m_size);
      return array[index];
    }

    void insert(const T& item, int index) {
      assert(index >= 0 && index <= m_size);
      if (m_size >= capacity) {
        resize();
      }

      for(int i = m_size; index < i; i--) {
        array[i] = array[i - 1];
      }

      m_size++;
      array[index] = item;
    }

    void remove(int index) {
      assert(index >= 0 && index < m_size);
      m_size--;
      for (int i = index; i < m_size; i++) {
        array[i] = array[i + 1];
      }
    }

    friend std::ostream& operator<<(std::ostream& os, const ArrayList<T>& dt) {
      for (int i = 0; i < dt.size(); i++) {
        os << dt.array[i] << " ";
      }
      os << std::endl;
      return os;
    }
};

#endif //ARRAYLIST_ARRAYLIST_H
