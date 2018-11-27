#include "binarysearchtree.h"
#include <cmath>
#include <fstream>
#include <iostream>

BinarySearchTree::BinarySearchTree() { this->root = nullptr; }
BinarySearchTree::BinarySearchTree(const char* filename) {
  this->root = nullptr;
  std::ifstream file(filename);
  if (file.is_open()) {
    int number;
    while (file >> number) {
      insertValue(number);
    }
  } else {
    std::cout << "Cannot open file" << std::endl;
  }
}
BinarySearchTree::~BinarySearchTree() {}
void BinarySearchTree::insertValue(int value) {
  if (root == nullptr) {
    root = new Node(value);
    return;
  }
  Node* temp = root;
  while (true) {
    if (temp->data < value) {
      if (temp->right == nullptr) {
        temp->right = new Node(value);
        break;
      } else
        temp = temp->right;
    } else if (temp->data > value) {
      if (temp->left == nullptr) {
        temp->left = new Node(value);
        break;
      } else
        temp = temp->left;
    } else
      return;
  }
}

void BinarySearchTree::printTree() {
  Node* temp = root;
  int depth = countDepth(temp);
  for (int i = 1; i <= depth; i++) {
    printLevel(root, i);
    std::cout << std::endl;
  }
}

int BinarySearchTree::countDepth(Node* root) {
  if (root == nullptr) return 0;
  int leftHeight = countDepth(root->left);
  int rightHeight = countDepth(root->right);
  return std::max(leftHeight + 1, rightHeight + 1);
}

void BinarySearchTree::printLevel(Node* node, int level) {
  if (node == nullptr) return;
  if (level == 1)
    std::cout << node->data << " ";
  else {
    printLevel(node->left, level - 1);
    printLevel(node->right, level - 1);
  }
}

Node* BinarySearchTree::searchValue(int value) {
  Node* temp = root;
  Node* found = nullptr;
  while (temp != nullptr && temp->data != value) {
    if (temp->data < value)
      temp = temp->right;
    else if (temp->data > value)
      temp = temp->left;
    else {
      found = temp;
      break;
    }
  }
  return found;
}

void BinarySearchTree::remove(int value) { remove(root, value); }

Node* BinarySearchTree::remove(Node* root, int value) {
  if (root == nullptr) return root;
  if (root->data < value) {
    root->right = remove(root->right, value);
  } else if (root->data > value) {
    root->left = remove(root->left, value);
  } else {
    if (!root->left) {
      Node* temp = root->right;
      delete root;
      return temp;
    } else if (!root->right) {
      Node* temp = root->left;
      delete root;
      return temp;
    } else {
      Node* minParent = root->right;
      Node* min = root->right;
      while (min->left != nullptr) {
        minParent = min;
        min = min->left;
      }

      minParent->left = min->right;
      root->data = min->data;
      delete min;
      return root;
    }
  }
  return nullptr;
}
