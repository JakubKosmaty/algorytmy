//
// Created by jakub on 10.12.2020.
//

#ifndef PRIORITY_QUEUE_PRIORITYQUEUE_H
#define PRIORITY_QUEUE_PRIORITYQUEUE_H

template <typename T>
struct SingleNode {
    T value;
    int priority{};
    SingleNode* next;
    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, const int prio, SingleNode* ptr = nullptr) : value(item), priority(prio), next(ptr) {}
};

template<typename T>
class PriorityQueue {
    SingleNode<T>* head;
public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue() {
        clear();
    }

    PriorityQueue(const PriorityQueue& other) {
        head = nullptr;
        SingleNode<T>* node = other.head;
        while (node != nullptr) {
            push(node->value, node->priority);
            node = node->next;
        }
    }

    PriorityQueue(PriorityQueue&& other) {
        head = std::move(other.head);
        other.head = nullptr;
    }

    PriorityQueue& operator=(const PriorityQueue& other) {
        if (this == &other) {
            return *this;
        }

        clear();
        SingleNode<T>* node = other.head;
        while (node != nullptr) {
            push(std::move(node->value), node->priority);
            node = node->next;
        }
        return *this;
    }

    PriorityQueue& operator=(PriorityQueue&& other) {
        if (this == &other) {
            return *this;
        }

        clear();
        head = std::move(other.head);
        other.head = nullptr;
        return *this;
    }

    bool empty() const {
        return head == nullptr;
    }

    int size() const {
        int size = 0;
        SingleNode<T>* node = head;
        while (node != nullptr) {
            node = node->next;
            size++;
        }
        return size;
    }

    void push(const T& item, const int priority) {
        SingleNode<T>* tempHead = new SingleNode<T>(item, priority);

        if (empty()) {
            head = tempHead;
            return;
        }

        SingleNode<T>* node = head;

        if (head->priority < priority) {
          tempHead->next = head;
            head = tempHead;
        } else {
            while (node->next != nullptr && priority < node->next->priority) {
                node = node->next;
            }
            tempHead->next = node->next;
            node->next = tempHead;
        }
    }

    void push(T&& item, const int priority) {
        SingleNode<T>* tempNode = new SingleNode<T>(std::forward<T>(item), priority);

        if (empty()) {
            head = tempNode;
            return;
        }

        SingleNode<T>* node = head;

        if (head->priority < priority) {
            tempNode->next = head;
            head = tempNode;
        }
        else {
            while (node->next != nullptr && priority < node->next->priority) {
                node = node->next;
            }
            tempNode->next = node->next;
            node->next = tempNode;
        }
    }

    T& top() const {
        return head->value;
    }

    void pop() {
        assert(!empty());
        SingleNode<T>* node = head;
        head = head->next;
        delete node;
    }

    void clear() {
        for (SingleNode<T>* node; !empty();) {
            node = head->next;
            delete head;
            head = node;
        }
    }

    void display() const {
        SingleNode<T>* node = head;
        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
};

#endif //PRIORITY_QUEUE_PRIORITYQUEUE_H