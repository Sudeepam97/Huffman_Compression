#include <iostream>
#include <vector>
#include <string>
#include "node_definition.h"
#include "read_text_file.h"
#include "create_list.h"
#include "create_huffman_tree.h"

/* SUMMARY
-------------
We read a text file or an image and extract all the unique characters/pixel
values and their frequencies and store them in a doubly linked list kind of
data structure. Refer the source file called 'node_definition.h' for more
details about the data structure used. This list is eventually destroyed and
is converted into a binary tree, as directed by the Huffman's algorithm.
Then, we read the character encodings from the tree and write them into a
binary file to encrypt and compress the original text file/image. */

node *first_node = NULL; //points to the first_node of the list.
node *last_node = NULL;  //points to the last_node node of the list.
int list_size = 0;
std::vector<std::string> codes;
std::vector<char> characters;

void traverse_tree(node*, char[], int);
void print_codes();

int main() {
  std::string message = read_text_file(); // Read the text file.
  //std::cout << message << "\n";
  create_list(message); // Create a doubly linked list.
  //print_list();
  create_huffman_tree();
  node *root = first_node;

  char this_code[64] = {'\0'};
  int code_length = 0;
  traverse_tree(root, this_code, code_length); // Print the Huffman Codes.
  list_size = characters.size();
  std::cout << "The size is: " << list_size << '\n';
  print_codes();
  return 1;
}

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
    characters.push_back(root->data);
    for (int i = 0; i < code_length; ++i)
      str = str + this_code[i] ;
    codes.push_back(str);
    //str = "";
  }
}

void print_codes(){
  for (int i = 0; i < list_size; i++){
    std::cout << characters.at(i) << '\t' << codes.at(i) << "\n";
  }
}
