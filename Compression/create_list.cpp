#include <iostream>
#include <tuple>
#include <vector>
#include "node_definition.h"
#include "create_list.h"

std::tuple <node*, node*, int> create_list(std::vector <int> raw_data, int debug){
  node *first_node = NULL; // Pointer to the first_node of the list.
  node *last_node = NULL;  // Pointer to the last_node node of the list.
  int list_size = 0;
  int freq[256] = {0}; // A maximum of 256 'unique' chars/pixels are possible.

  for (int i = 0; i < raw_data.size(); i++){
    freq[raw_data.at(i)]++;
  }

  for (int i = 0; i < raw_data.size(); i++){
    if (freq[raw_data[i]] != 0){
      // Create a node and fill all its entries.
      node *new_node = new node;
      new_node->data = raw_data[i];
      new_node->freq = freq[raw_data[i]];
      new_node->left = NULL;
      new_node->leftc = NULL;
      new_node->right = NULL;
      new_node->rightc = NULL;
      // Connect with existing nodes.
      if(first_node == NULL){
        first_node = new_node;
        last_node = new_node;
      }
      else {
        last_node->right = new_node;
        new_node->left = last_node;
        last_node = new_node;
      }
      // Count the number of unique chars/pixels
      list_size++;
      freq[raw_data[i]] = 0;
    }
  }

  if (debug == 1){
    print_list(first_node, last_node, list_size);
  }

  std::tuple <node*, node*, int> list;
  list = std::make_tuple(first_node, last_node, list_size);
  return list;
}


void print_list(node *first_node, node *last_node, int list_size){
  node *c = first_node; //c is used as a counter variable
  std::cout << "The unique characters and their frequencies are:" << "\n";
  while (c != NULL){
    std::cout << c->data << "\t" << "\t" << c->freq << "\n";
    c = c->right;
  }
  std::cout << "\n" << "Length of the list is: " << list_size << "\n" << "\n";
}
