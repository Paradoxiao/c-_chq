#include <iostream>
struct node {
  int data;
  node *left, *right;
};
void create(node *tree) {
  int i;
  std::cin >> i;
  tree->data = i;
  if (i == -1)
    return;
  tree->left = new node;
  tree->right = new node;
  create(tree->left);
  create(tree->right);
}
