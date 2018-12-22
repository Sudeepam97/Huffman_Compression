#include <iostream>
#include "node_definition.h"
#include "insert_new.h"

extern int list_size;
extern node *first_node;
extern node *last_node;

void insert_new(node *new_node) {
  if(first_node == NULL) {
    first_node = new_node;
  }
  else {
    last_node->right = new_node;
    new_node->left = last_node;
    last_node = new_node;
  }
}
