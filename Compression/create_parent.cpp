#include <iostream>
#include "node_definition.h"
#include "create_parent.h"

node* create_parent (node *lchild, node *rchild) {
  node *p = new node; // A pointer to our newly created parent node
  p->data = 256; // Any garbage would work but we choose 256 because our main int values are between 0-255
  p->left = NULL;
  p->right = NULL;
  p->freq = lchild->freq + rchild->freq;
  p->leftc = lchild;
  p->rightc = rchild;
  return p;
}
