#include <iostream>
#include "headers/node_definition.h"
#include "headers/insert_new.h"

void insert_new(node *new_node, node **first_node, node **last_node){
  if(*first_node == NULL){ // The Huffman tree has been created.
    // Set 'first_node' to be the root of the Huffman tree.
    *first_node = new_node;
  }
  else {
    (*last_node)->right = new_node;
    new_node->left = *last_node;
    *last_node = new_node;
  }
}
