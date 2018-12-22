#include "node_definition.h"
#include "extract_min.h"
#include "create_parent.h"
#include "insert_new.h"
#include "create_huffman_tree.h"

extern int list_size;
extern node *first_node;
extern node *last_node;

void create_huffman_tree() {
  node *lc, *rc, *parent;
  while(list_size != 0) {
    lc = extract_min(); // Extract the left child for the currrent iteration
    list_size--;
    rc = extract_min(); // Extract the right child for the current iteration
    list_size--;
    parent = create_parent(lc, rc); // Parent of the currrent right and left child
    insert_new(parent); // Insert this parent node into our list
    if(list_size != 0){
      list_size++;
    }
  }
}
