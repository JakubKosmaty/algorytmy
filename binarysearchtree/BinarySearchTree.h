//
// Created by Jakub Kosmaty on 17/12/2020.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include <queue>
#include <cassert>
#include <stack>

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
class BinarySearchTree {
    BSTNode<T>* root;
public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {}

    bool empty() const {
      return root == nullptr;
    }

    T& top() {
      assert(root != nullptr);
      return root->value;
    }
    void insert(const T& item) {
      root = insert(root, item);
    }

    void remove(const T& item) {
      BSTNode<T>* node = root;
      BSTNode<T>* prev = nullptr;
      while (node != nullptr) {
        if (node->value == item)
          break;
        prev = node;
        if (item < node->value) {
          node = node->left;
        } else {
          node = node->right;
        }
      }
      if (node != nullptr && node->value == item) {
        if (node == root) {
          root = remove(node);
        } else if (prev->left == node) {
          prev->left = remove(node);
        } else {
          prev->right = remove(node);
        }
      } else if (root != nullptr) {
      } else {
      }
    }

    T* search(const T& item) const {
      auto ptr = search(root, item);
      return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }

    T find_max() const {
      assert(!empty());
      BSTNode<T>* tempNode = root;
      while (tempNode->right != nullptr) {
        tempNode = tempNode->right;
      }

      return (tempNode->value);
    }

    T find_min() const {
      assert(!empty());
      BSTNode<T>* tempNode = root;
      while (tempNode->left != nullptr) {
        tempNode = tempNode->left;
      }

      return (tempNode->value);
    }

    bool isBST() const {
      return isBST(root);
    }

    bool isBST(BSTNode<T>* rootNode, BSTNode<T>* leftNode = nullptr,  BSTNode<T>* rightNode = nullptr) const {
      if (rootNode == nullptr) {
        return true;
      }

      if (leftNode != nullptr && (rootNode->value <= leftNode->value)) {
        return false;
      }

      if (rightNode != nullptr && (rootNode->value >= rightNode->value)) {
        return false;
      }

      return isBST(rootNode->left, leftNode, rootNode) && isBST(rootNode->right, rootNode, rightNode);
    }

    BSTNode<T>* insert(BSTNode<T> *node, const T& item) {
      if (node == nullptr) {
        return new BSTNode<T>(item);
      }
      if (item < node->value) {
        node->left = insert(node->left, item);
      } else {
        node->right = insert(node->right, item);
      }
      return node;
    }

    BSTNode<T>* search(BSTNode<T> *node, const T& item) const {
      if (node == nullptr || node->value == item) {
        return node;
      } else if (item < node->value) {
        return search(node->left, item);
      } else {
        return search(node->right, item);
      }
    }

    BSTNode<T>* remove(BSTNode<T> *node) {
      assert(node != nullptr);
      BSTNode<T> *new_root;
      if (node->right == nullptr) {
        new_root = node->left;
      } else if (node->left == nullptr) {
        new_root = node->right;
      } else {
        new_root = node;
        node = node->left;
        while (node->right != nullptr) {
          node = node->right;
        }
        node->right = new_root->right;
        node = new_root;
        new_root = node->left;
      }
      delete node;
      return new_root;
    }

    virtual void visit(BSTNode<T> *node) {
      assert(node != nullptr);
      std::cout << "visiting " << node->value << std::endl;
    }
};

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
