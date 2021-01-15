//
// Created by Jakub Kosmaty on 17/12/2020.
//

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

template <typename T>
struct AVLNode {
    T value;
    int balance;
    AVLNode* left;
    AVLNode* right;
    AVLNode* parent;
    AVLNode() : value(T()), balance(0), left(nullptr), right(nullptr), parent(nullptr) {}
    AVLNode(const T& item, AVLNode *p) : value(item), balance(0), left(nullptr), right(nullptr), parent(p) {}
    ~AVLNode() {}
};

template <typename T>
class AVLTree {
private:
    AVLNode<T> *root;

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        clear();
    }

    bool empty() const {
        return root == nullptr;
    }

    T& top() {
        assert(root != nullptr); return root->value;
    }

    int height() {
        return height(root);
    }

    int height(AVLNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }

    bool isAVL() {
      return isAVL(root);
    }

    bool isAVL(AVLNode<T>* root) {
        if (root == nullptr) {
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (1 >= abs(leftHeight - rightHeight) && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }

        return false;
    }

    bool insert(const T& item);

    void remove(const T& item);

    T* search(const T& item) const {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }

    void preorder() {
        preorder(root);
    }

    void inorder() {
        inorder(root);
    }

    void postorder() {
        postorder(root);
    }

    void bfs();

    T* find_max();

    T* find_min();

    void clear() {
        clear(root);
        root = nullptr;
    }
    void display() {
        display(root, 0);
    }

    virtual void visit(AVLNode<T> *node) {
        assert(node != nullptr);
        std::cout << "visiting " << node->value << std::endl;
    }
};

#endif //AVLTREE_AVLTREE_H
