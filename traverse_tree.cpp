#include <string>
#include <map>
#include "node_definition.h"
#include "traverse_tree.h"

extern std::map <char, std::string> encoder;

void traverse_tree(node* root, char this_code[], int code_length) {
  // Assign 0 to left edge and recur, if root->leftc != NULL)
  if (root->leftc) {
    this_code[code_length]= '0';
    traverse_tree(root->leftc, this_code, code_length + 1);
  }
  // Assign 1 to right edge and recur, if root->rightc != NULL)
  if (root->rightc) {
    this_code[code_length] = '1';
    traverse_tree(root->rightc, this_code, code_length + 1);
  }
  // Check if we are at a leaf node
  if (!(root->leftc) && !(root->rightc)) {
    std::string str = "";
    for (int i = 0; i < code_length; ++i)
      str = str + this_code[i] ;
    encoder.insert(std::pair <char, std::string>(root->data, str));
  }
}
