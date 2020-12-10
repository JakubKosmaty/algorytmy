//
// Created by jakub on 26.11.2020.
//

#ifndef QUEUE_MYQUEUE_H
#define QUEUE_MYQUEUE_H

template <typename T>
class MyQueue {
private:
    T* tab;
    int msize;
    int head;
    int tail;

    void init(int s = 10) {
        tab = new T[s + 1];
        assert(tab != nullptr);

        msize = s + 1;
        head = 0;
        tail = 0;
    }

public:
    MyQueue(int s = 10)  {
        init(s);
    }

    ~MyQueue() {
        delete[] tab;
    }

    MyQueue(const MyQueue& other) {
        msize = other.msize;
        head = other.head;
        tail = other.tail;

        tab = new T[other.msize];

        for (int i = other.head; i != other.tail; i = (i + 1) % other.msize) {
            tab[i] = other.tab[i];
        }
    }

    MyQueue(MyQueue&& other) {
        msize = std::move(other.msize);
        head = std::move(other.head);
        tail = std::move(other.tail);
        tab = std::move(other.tab);
        other.init();
    }

    MyQueue& operator=(const MyQueue& other) {
        if (this == &other) {
            return *this;
        }

        msize = other.msize;
        head = other.head;
        tail = other.tail;

        for (int i = other.head; i != other.tail; i = (i + 1) % other.msize) {
            tab[i] = other.tab[i];
        }

        return *this;
    }

    MyQueue& operator=(MyQueue&& other) {
        if (this == &other) {
            return *this;
        }

        msize = std::move(other.msize);
        head = std::move(other.head);
        tail = std::move(other.tail);
        tab = std::move(other.tab);
        other.init();

        return *this;
    }

    bool empty() const {
        return head == tail;
    }

    bool full() const {
        return (head + msize -1) % msize == tail;
    }

    int size() const {
        return (tail - head + msize) % msize;
    }

    int max_size() const {
        return msize - 1;
    }

    void push(const T& item) {
        assert(!full());
        tab[tail] = item;
        tail = (tail + 1) % msize;
    }

    void push(T&& item) {
        assert(!full());
        tab[tail] = std::move(item);
        tail = (tail + 1) % msize;
    }

    T& front() {
        assert(!empty());
        return tab[head];
    }

    T& back() {
        assert(!empty());
        return tab[(tail + msize -1) % msize];
    }

    void pop() {
        assert(!empty());
        head = (head + 1) % msize;
    }

    void clear(int s = 10) {
        delete[] tab;
        init();
    }

    void display() {
        for (int i = head; i != tail; i = (i + 1) % msize) {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif //QUEUE_MYQUEUE_H
