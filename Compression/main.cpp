#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include "headers/node_definition.h"
#include "headers/read_text_file.h"
#include "headers/read_image.h"
#include "headers/create_list.h"
#include "headers/create_huffman_tree.h"
#include "headers/traverse_tree.h"
#include "headers/compress_data.h"

/* SUMMARY
-------------
We read a text file or an image and extract all the unique characters/pixel
values and their frequencies and store them in a data structure that is similar
to a doubly linked list. The nodes of this list are then reconnected by
following the Huffman's algorithm to create a binary tree.

Refer the source of the file called 'node_definition.h' for more details about
the data structure used.

After the creation of the tree, we read the Huffman codes for each character
and store the character-code pair in a hashmap. We replace each character or
pixel in the orignal text/image by its equivalent Huffman code and write this
bit stream into a new file to finally compress the original text/image.
*/

std::map <int, std::string> encoder;

int main(int argc, char* argv[]){
  // Ask if debug mode is required.
  std::cout << "Press '1' for debug mode and '2' for compression only: ";
  int debug;
  std::cin >> debug;
  std::cout << '\n';

  // Read the text file or the image according to the users choice.
  char choice = *argv[1];
  std::vector<int> raw_data;
  if (choice == '1')
    raw_data = read_text_file();
  else if (choice == '2')
    raw_data = read_image();
  else {
    std::cout << "error: invalid choice: Press '1' for Text and '2' for images";
    std::cout << "\n";
    return 1;
  }

  /* Extract all unique characters/pixel values and their frequencies
     and store this data in a doubly linked list. */
  std::tuple <node*, node*, int> list = create_list(raw_data, debug);

  // Convert this list into the Huffman tree and return the address of its root.
  node *root = create_huffman_tree(list);

  // Read codes from the Huffman Tree.
  int index = 0;
  // Reasonably assuming that code lengths are not >64
  char this_code[64] = {'\0'};
  traverse_tree(root, this_code, index); // Get the Huffman Codes.

  // For debugging
  if (debug == 1){
    std::cout << "\n" << "Tree formation complete!" << "\n" << "\n";
    int num_uniq_vals = 0;
    num_uniq_vals = encoder.size();
    std::cout << "Number of unique characters are: " << num_uniq_vals << '\n';
    print_codes(num_uniq_vals);
  }
  
  std::cout << "Compressing your file. It will take a few moments..." << "\n";
  compress_data(raw_data, choice);
  return 1;
}

void print_codes(int num_uniq_vals){
  std::map <int, std::string>::iterator itr;
  for (itr = encoder.begin(); itr != encoder.end(); ++itr){
    std::cout << itr->first << '\t' << itr->second << "\n";
  }
  std::cout << "\n";
}
