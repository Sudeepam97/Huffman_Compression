#include <iostream>
#include "headers/node_definition.h"
#include "headers/create_parent.h"

node* create_parent (node *lchild, node *rchild){
  node *p = new node; // Pointer to our newly created parent node
  p->data = 2000;     // Some garbage value.
  p->left = NULL;
  p->right = NULL;
  p->freq = lchild->freq + rchild->freq;
  p->leftc = lchild;
  p->rightc = rchild;
  return p;
}
