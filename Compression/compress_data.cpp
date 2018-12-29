#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <bitset>
#include "node_definition.h"
#include "compress_data.h"

extern std::map <char, std::string> encoder;

void compress_data (std::string msg){
  std::string bit_seq = "", group = "", encrypted = "";
  for (int i = 0; i < msg.size(); i++)
    bit_seq = bit_seq + encoder.at(msg[i]);
  for (int i = 0; i < bit_seq.size(); i++) {
    group = group + bit_seq[i];
    if (group.size() == 8) {
      encrypted = encrypted + str_to_char(group);
      group = "";
    }
  }
  std::string edge_case((8 - group.size()), '0');
  edge_case = group + edge_case;
  encrypted = encrypted + str_to_char(edge_case);
  std::ofstream f, g;
  f.open ("compressed/data.txt");
  g.open ("compressed/key.txt");
  f << (8 - group.size()) << encrypted;
  std::map <char, std::string>::iterator itr;
  for (itr = encoder.begin(); itr != encoder.end(); ++itr) {
    g << itr->first << '\n' << itr->second << "\n";
  }
  std::cout << "Done. Look inside the directory named 'compressed'" << "\n";
  f.close();
  g.close();
}

char str_to_char(std::string group)
{
    std::bitset<8> temp(group);
    return temp.to_ulong();
}
