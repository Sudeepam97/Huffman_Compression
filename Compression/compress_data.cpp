#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <bitset>
#include "node_definition.h"
#include "compress_data.h"

extern std::map <char, std::string> encoder;

void compress_data (std::string msg){
  std::string bit_seq = "", group = "0", encrypted = "";
  for (int i = 0; i < msg.size(); i++)
    bit_seq = bit_seq + encoder.at(msg[i]);
  std::cout << bit_seq << '\n';
  for (int i = 0; i < bit_seq.size(); i++) {
    group = group + bit_seq[i];
    if (group.size() == 8) {
      encrypted = encrypted + str_to_char(group);
      group = "0";
    }
  }
  std::string edge_case((8 - group.size()), '0');
  edge_case = edge_case + group;
  encrypted = encrypted + str_to_char(edge_case);
  std::ofstream f;
  f.open ("compressed.txt");
  f << group.size() << encrypted;
  std::cout << "done" << "\n";
  f.close();
}

char str_to_char(std::string group)
{
    std::bitset<8> temp(group);
    return temp.to_ulong();
}
