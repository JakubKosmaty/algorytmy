//
// Created by Jakub Kosmaty on 17/12/2020.
//

#ifndef BINARYTREE_RANDOMBINARYTREE_H
#define BINARYTREE_RANDOMBINARYTREE_H

#include <stack>
#include <queue>
#include <cassert>

template <typename T>
struct BSTNode {
    T value;
    BSTNode* left;
    BSTNode* right;
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    BSTNode(const T& item, BSTNode* le = nullptr, BSTNode* ri = nullptr) : value(item), left(le), right(ri) {}
    ~BSTNode() {}
};

template <typename T>
class RandomBinaryTree {
private:
    BSTNode<T>* root;

    int count_leafs_helper(BSTNode<T>* node) {
      if (node == nullptr) {
        return 0;
      }
      if (node->left == nullptr && node->right == nullptr) {
        return 1;
      } else {
        return count_leafs_helper(node->left) + count_leafs_helper(node->right);
      }
    }

    int iter_count_leafs_helper() {
      if (root == nullptr) {
        return 0;
      }

      std::queue<BSTNode<T>*> queueTemp;
      BSTNode<T>* nodeTemp = root;
      queueTemp.push(nodeTemp);
      int count = 0;
      while (!queueTemp.empty()) {
        nodeTemp = queueTemp.front();
        queueTemp.pop();
        if (nodeTemp->left != nullptr) {
          queueTemp.push(nodeTemp->left);
        }
        if (nodeTemp->right != nullptr) {
          queueTemp.push(nodeTemp->right);
        }
        if (nodeTemp->left == nullptr && nodeTemp->right == nullptr) {
          count++;
        }
      }
      return count;
    }

    int find_max_min_helper(BSTNode<T>* node, const int type) {
      if (node == nullptr) {
        return type == 0 ? INT_MAX : INT_MIN;
      }

      int value = node->value;
      int left = find_max_min_helper(node->left, type);
      int right = find_max_min_helper(node->right, type);

      if ((type == 0) ? value > left : value < left) {
        value =  left;
      }

      if ((type == 0) ? value > right : value < right) {
        value = right;
      }
      return value;
    }

    int iter_find_max_min_helper(const int type) {
      std::queue<BSTNode<T>*> queueTemp;
      BSTNode<T>* nodeTemp = root;
      queueTemp.push(nodeTemp);
      int minMax = type == 0 ? INT_MAX : INT_MIN;
      while (!queueTemp.empty()) {
        nodeTemp = queueTemp.front();
        queueTemp.pop();

        if ((type == 0) ? minMax > nodeTemp->value : minMax < nodeTemp->value) {
          minMax = nodeTemp->value;
        }

        if (nodeTemp->left != nullptr) {
          queueTemp.push(nodeTemp->left);
        }
        if (nodeTemp->right != nullptr) {
          queueTemp.push(nodeTemp->right);
        }
      }
      return minMax;
    }

public:
    RandomBinaryTree() : root(nullptr) {}

    ~RandomBinaryTree() {
      clear();
    }

    bool empty() const {
      return root == nullptr;
    }

    T& top() {
      assert(root != nullptr); return root->value;
    }

    void insert(const T& item) {
      root = insert(root, item);
    }

    T* search(const T& item) const {
      auto ptr = search(root, item);
      return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }

    int count_leafs(const int type) {
      switch (type) {
        case 0: return count_leafs_helper(root);
        case 1: return iter_count_leafs_helper();
        default: return -1;
      }
    }

    int find_max() {
      assert(!empty());
      return find_max_min_helper(root, 1);
    }

    int find_min() {
      assert(!empty());
      return find_max_min_helper(root, 0);
    }

    int iter_find_max() {
      assert(!empty());
      return iter_find_max_min_helper(1);
    }

    int iter_find_min() {
      assert(!empty());
      return iter_find_max_min_helper(0);
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

    void iter_preorder() {
      if (root == nullptr) {
        return;
      }
      std::stack<BSTNode<T>*> S;
      BSTNode<T> *node = root;
      S.push(node);
      while (!S.empty()) {
        node = S.top();
        S.pop();
        visit(node);
        if (node->right != nullptr) {
          S.push(node->right);
        }
        if (node->left != nullptr) {
          S.push(node->left);
        }
      }
    }

    void bfs() {
      if (root == nullptr) {
        return;
      }
      std::queue<BSTNode<T>*> Q;
      BSTNode<T>* node = root;
      Q.push(node);
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        visit(node);
        if (node->left != nullptr) {
          Q.push(node->left);
        }
        if (node->right != nullptr) {
          Q.push(node->right);
        }
      }
    }

    void clear() {
      clear(root);
      root = nullptr;
    }
    void display() {
      display(root, 0);
    }

    void clear(BSTNode<T>* node) {

    }

    BSTNode<T>* insert(BSTNode<T>* node, const T& item) {
      if (node == nullptr) {
        return new BSTNode<T>(item);
      }
      if (std::rand() % 2) {
        node->left = insert(node->left, item);
      } else {
        node->right = insert(node->right, item);
      }
      return node;
    }

    BSTNode<T>* search(BSTNode<T>* node, const T& item) const {
      if (node == nullptr || node->value == item) {
        return node;
      }
      T* ptr;
      ptr = search(node->left, item);
      if (ptr == nullptr) {
        ptr = search(node->right, item);
      }
      return ptr;
    }

    void preorder(BSTNode<T>* node) {
      if (node == nullptr) {
        return;
      }
      visit(node);
      preorder(node->left);
      preorder(node->right);
    }

    void inorder(BSTNode<T>* node) {
      if (node == nullptr) {
        return;
      }
      inorder(node->left);
      visit(node);
      inorder(node->right);
    }

    void postorder(BSTNode<T>* node) {
      if (node == nullptr) {
        return;
      }
      postorder(node->left);
      postorder(node->right);
      visit(node);
    }

    void display(BSTNode<T>* node, int level) {
      if (node == nullptr) {
        return;
      }
      display(node->right, level + 1);
      std::cout << std::string(3 * level, ' ') << node->value << std::endl;
      display(node->left, level + 1);
    }

    virtual void visit(BSTNode<T>* node) {
      assert(node != nullptr);
      std::cout << "visiting " << node->value << std::endl;
    }
};

#endif //BINARYTREE_RANDOMBINARYTREE_H
