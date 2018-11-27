#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BinarySearchTree {
 private:
  Node* root;

 public:
  BinarySearchTree();
  BinarySearchTree(const char* filename);
  ~BinarySearchTree();
  void printTree();
  void insertValue(int value);
  void deleteValue();
  Node* searchValue(int value);
  int countDepth(Node* node);
  void printLevel(Node* node, int level);
  Node* remove(Node* root, int value);
  void remove(int value);
  Node* findMin(Node* node);
};

#endif  // BINARYSEARCHTREE_H
