#include <iostream>
#include "node_definition.h"
#include "insert_new.h"

void insert_new(node *new_node, node **first_node, node **last_node) {
  if(*first_node == NULL) {
    *first_node = new_node;
  }
  else {
    (*last_node)->right = new_node;
    new_node->left = *last_node;
    *last_node = new_node;
  }
}