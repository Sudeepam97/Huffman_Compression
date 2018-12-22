#include <tuple>
#include <iostream>
#include "node_definition.h"
#include "extract_min.h"
#include "create_parent.h"
#include "insert_new.h"
#include "create_huffman_tree.h"

std::tuple<node*, int> create_huffman_tree(std::tuple <node*, node*, int> list){
  node *lc = NULL, *rc = NULL, *parent = NULL;
  node *first_node = NULL, *last_node = NULL;
  int list_size = 0;
  std::tie(first_node, last_node, list_size) = list;
  while(list_size != 0) {
    lc = extract_min(&first_node, &last_node); // Extract the left child for the currrent iteration
    list_size--;
    rc = extract_min(&first_node, &last_node); // Extract the right child for the current iteration
    list_size--;
    parent = create_parent(lc, rc); // Parent of the currrent right and left child
    insert_new(parent, &first_node, &last_node); // Insert this parent node into our list
    if(list_size != 0){
      list_size++;
    }
  }
  std::tuple <node*, int> tree;
  tree = std::make_tuple(first_node, list_size);
  return tree;
}
