#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include "node_definition.h"
#include "compress_data.h"

extern std::map <int, std::string> encoder;

void compress_data (std::vector <int> raw_data, int choice){

  // Write the key to the file.
  std::ofstream key("compressed/decryption_map.txt");
  std::map <int, std::string>::iterator itr;
  for (itr = encoder.begin(); itr != encoder.end(); ++itr) {
    key << itr->first << '\n' << itr->second << "\n";
  }

  // Generate the bit stream (minus the edge cases)
  std::string bit_seq = "";
  for (int i = 0; i < raw_data.size(); i++)
    bit_seq = bit_seq + encoder.at(raw_data[i]);

  // Include the information about unnecessary bits and text/image bit in the key.
  key << generate_file(bit_seq) << "\n" << choice;
  key.close();

  std::cout << "Done. Look inside the directory named 'compressed'" << "\n";
}

int generate_file (std::string bit_seq){
  std::string group = "";
  std::ofstream f("compressed/data.txt");
  // Generate the enrypted message (minus the edge case)
  for (int i = 0; i < bit_seq.size(); i++) {
    group = group + bit_seq[i];
    if (group.size() == 8) {
      f << str_to_char(group) << "\n";
      group = "";
    }
  }
  // Calculate the number of extra bits and generate the edge case
  std::string edge_case((8 - group.size()), '0');
  f << str_to_char(group + edge_case);
  f.close();
  return (8 - group.size());
}

int str_to_char(std::string group){
    std::bitset<8> temp(group);
    return temp.to_ulong();
}
