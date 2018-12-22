#include <iostream>
#include <string>
#include "node_definition.h"
#include "create_list.h"

extern int list_size;
extern node *first_node;
extern node *last_node;

void create_list(std::string str) {
  int freq = 0;
  std::string str_copy = str;
  // Loop over the entire message string.
  for (int i = 0; i < str.size(); i++) {
    // Calculate the frequency of the given character
    for (int j = 0; j < str.size(); j++) {
      if (str[j] != '\0' && str[j] == str[i]) {
        freq ++;
        str_copy[j] = '\0';
      }
    }
    if (str[i] != '\0'){
      // Create a node and fill all its entries.
      node *new_node = new node;
      new_node->data = str[i];
      new_node->freq = freq;
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
    }
    freq = 0;
    str = str_copy;
  }
}

void print_list(){
  node *c = first_node; //c is used as a counter variable
  while (c != NULL){
    std::cout << c->data << "\t" << c->freq << "\n";
    c = c->right;
  }
  std::cout << "\n" << "ohh, and the length is: " << list_size << "\n\n";
}
