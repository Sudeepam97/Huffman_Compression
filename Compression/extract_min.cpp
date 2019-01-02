#include <iostream>
#include "node_definition.h"
#include "extract_min.h"

/* Traverse through the linked list and find the node having
the minimum value of frequency (freq). Remove this node from
the list and make appropriate connections to preserve the
structure of the rest of the list. */

node* extract_min(node **first_node, node **last_node){
  node *min = *first_node; // 'min' will store the address of minimum node
  if (*first_node == *last_node){
    // Only one node is left and it will be the minimum node.
    *first_node = NULL;
    *last_node = NULL;
    return min;
  }
  else {
    /* Traverse the list using 'temp' and make 'min' point to
       the node having the least value of frequency (freq). */
    node *temp = *first_node;
    while (temp->right != NULL){
      temp = temp->right;
      if(min->freq > temp->freq){
        min = temp;
      }
    }
    /* If the first node is removed, we make 'first_node'
       point the second node of the original list. */
    if (min == *first_node){
      *first_node = (*first_node)->right;
      (*first_node)->left = NULL;
    }
    /* If the last node is removed, we make 'last_node' point
       the second last node of the original list. */
    else if (min == *last_node){
      *last_node = (*last_node)->left;
      (*last_node)->right = NULL;
    }
    /* Otherwise, we need to connenct the nodes that were orignially
       present to the left and right of minimum node. */
    else {
      temp = min->left;
      temp->right = min->right;
      temp = min->right;
      temp->left = min->left;
    }
    /* Finally, we completely remove the minimum node
       from the list and return a pointer to it. */
    min->left = NULL;
    min->right = NULL;
    return min;
  }
}
