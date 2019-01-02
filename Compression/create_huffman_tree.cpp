#include <iostream>
#include <tuple>
#include "node_definition.h"
#include "extract_min.h"
#include "create_parent.h"
#include "insert_new.h"
#include "create_huffman_tree.h"

node* create_huffman_tree(std::tuple <node*, node*, int> list){
  node *lc = NULL, *rc = NULL, *parent = NULL;
  node *first_node = NULL, *last_node = NULL;
  int list_size = 0;
  std::tie(first_node, last_node, list_size) = list;
  while(list_size != 0){
    // Extract the left child for the currrent iteration
    lc = extract_min(&first_node, &last_node);
    list_size--;
    // Extract the right child for the current iteration
    rc = extract_min(&first_node, &last_node);
    list_size--;
    // Parent of the currrent left and right child
    parent = create_parent(lc, rc);
    // Insert this parent node into our list
    insert_new(parent, &first_node, &last_node);
    if(list_size != 0){
      list_size++;
    }
  }
  return first_node;
}
