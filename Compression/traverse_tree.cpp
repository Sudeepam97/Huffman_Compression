#include <string>
#include <unordered_map>
#include "headers/node_definition.h"
#include "headers/traverse_tree.h"

extern std::unordered_map <int, std::string> encoder;

void traverse_tree(node* root, char this_code[], int index){
  // Assign 0 to left edge and recur
  if (root->leftc){
    this_code[index]= '0';
    traverse_tree(root->leftc, this_code, index + 1);
  }
  // Assign 1 to right edge and recur
  if (root->rightc){
    this_code[index] = '1';
    traverse_tree(root->rightc, this_code, index + 1);
  }
  // Check if we are at a leaf node
  if (!(root->leftc) && !(root->rightc)){
    std::string code = "";
    for (int i = 0; i < index; ++i)
      code = code + this_code[i] ;
    encoder[root->data] = code;
  }
}
