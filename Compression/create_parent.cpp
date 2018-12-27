#include <iostream>
#include "node_definition.h"
#include "create_parent.h"

node* create_parent (node *lchild, node *rchild) {
  node *p = new node; // A pointer to our newly created parent node
  p->data = '\0';
  p->left = NULL;
  p->right = NULL;
  p->freq = lchild->freq + rchild->freq;
  p->leftc = lchild;
  p->rightc = rchild;
  return p;
}