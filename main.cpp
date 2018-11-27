#include <iostream>
#include <string>
#include "binarysearchtree.h"
int main() {
  std::string filename = "numbers.txt";
  BinarySearchTree bst = BinarySearchTree(filename.c_str());
  bst.printTree();
  bst.remove(5);
  bst.printTree();
  return 0;
}
