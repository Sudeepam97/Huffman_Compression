#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "node_definition.h"
#include "create_list.h"

std::tuple <node*, node*, int> create_list(std::vector <int> img) {
  node *first_node = NULL; //points to the first_node of the list.
  node *last_node = NULL;  //points to the last_node node of the list.
  int list_size = 0;
  int freq[256] = {0};

  for (int i = 0; i < img.size(); i++) {
    freq[img.at(i)]++;
  }

  for (int i = 0; i < img.size(); i++) {
    if (freq[img[i]] != 0) {
      // Create a node and fill all its entries.
      node *new_node = new node;
      new_node->data = img[i];
      new_node->freq = freq[img[i]];
      new_node->left = NULL;
      new_node->leftc = NULL;
      new_node->right = NULL;
      new_node->rightc = NULL;
      // Connect with existing nodes.
      if(first_node == NULL) {
        first_node = new_node;
        last_node = new_node;
      }
      else {
        last_node->right = new_node;
        new_node->left = last_node;
        last_node = new_node;
      }
      // Make sure to keep track of the number of items.
      list_size++;
      freq[img[i]] = 0;
    }
  }
  //print_list(first_node, last_node, list_size);
  std::tuple <node*, node*, int> list;
  list = std::make_tuple(first_node, last_node, list_size);
  return list;
}

/*
void print_list(node *first_node, node *last_node, int list_size){
  node *c = first_node; //c is used as a counter variable
  while (c != NULL){
    std::cout << c->data << "\t" << c->freq << "\n";
    c = c->right;
  }
  std::cout << "\n" << "ohh, and the length is: " << list_size << "\n\n";
}
*/
