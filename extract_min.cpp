#include <iostream>
#include "node_definition.h"
#include "extract_min.h"

extern int list_size;
extern node *first_node;
extern node *last_node;

// Traverse through the linked list and find the node having
// the minimum value of frequency (freq). Remove this node
// from the list and make appropriate connections to preserve
// the rest of the list.

node* extract_min() {
  node *min = first_node; // will used to store the address of minimum node
  if (first_node == last_node) { // there is only one node left and it will be the min node
    first_node = NULL;
    last_node = NULL;
    return min;
  }
  else {
    // Traverse using 'temp' and make 'min' point to the node having least value for freq.
    node *temp = first_node;
    for(int i = 1; i < list_size; i++) {
      temp = temp->right;
      if(min->freq > temp->freq) {
        min = temp;
      }
    }
    // If the first node gets removed, we make 'first_node' point
    // the second node of the original list.
    if (min == first_node) {
      first_node = first_node->right;
      first_node->left = NULL;
    }
    // If the last node gets removed, we make 'last_node' point
    // the second last node of the original list.
    else if (min == last_node) {
      last_node = last_node->left;
      last_node->right = NULL;
    }
    // Otherwise we need to connenct the nodes that were orignially
    // present to the left and right of minimum node.
    else {
      temp = min->left;
      temp->right = min->right;
      temp = min->right;
      temp->left = min->left;
    }
    // Finally, we completely remove the minimum node
    // from the list and return a pointer to it.
    min->left = NULL;
    min->right = NULL;
    return min;
  }
}
