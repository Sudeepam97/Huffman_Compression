#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include "node_definition.h"
#include "read_text_file.h"
#include "read_image.h"
#include "create_list.h"
#include "create_huffman_tree.h"
#include "traverse_tree.h"
#include "compress_data.h"

/* SUMMARY
-------------
We read a text file or an image and extract all the unique characters/pixel
values and their frequencies and store them in a doubly linked list kind of
data structure. Refer the source file called 'node_definition.h' for more
details about the data structure used. This list is eventually destroyed and
is converted into a binary tree, as directed by the Huffman's algorithm.
Then, we read the character encodings from the tree and write them into a
binary file to encrypt and compress the original text file/image. */

std::map <int, std::string> encoder;
//void print_codes(int);

int main() {
  std::tuple <node*, node*, int> list;
  std::tuple <node*, int> tree;
  int list_size = 0;
  node *root = NULL;

  // Changed
  int choice = 0;
  std::cout << "Text(1) or Image(2)?" << '\n';
  std::cin >> choice;

  std::vector<int> raw_data;

  if (choice == 1){
    raw_data = read_text_file(); // Read the text file
  }
  else if (choice == 2){
    raw_data = read_image(); // Read the image file.
  }
  else {
    std::cout << "invalid choice" << "\n";
    return 1;
  }

  list = create_list(raw_data);              // Create a doubly linked list.

  // No change
  tree = create_huffman_tree(list);
  std::tie(root, list_size) = tree;
  char this_code[64] = {'\0'};
  int code_length = 0;

  //changed
  traverse_tree(root, this_code, code_length); // Get the Huffman Codes.
  //list_size = encoder.size();
  //std::cout << "The size is: " << list_size << '\n';
  //print_codes(list_size);
  compress_data(raw_data, choice);
  return 1;
}

/*
void print_codes(int list_size){
  std::map <int, std::string>::iterator itr;
  for (itr = encoder.begin(); itr != encoder.end(); ++itr) {
    std::cout << itr->first << '\t' << itr->second << "\n";
  }
}*/
