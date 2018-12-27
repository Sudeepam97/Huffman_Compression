#include <iostream>
#include <map>
#include <string>
#include <fstream>
//#include <bitset>
#include "node_definition.h"
#include "compress_data.h"

extern std::map <char, std::string> encoder;

void compress_data (std::string msg){
  std::fstream f;
  std::string bit_seq = "";
  f = std::fstream("data.binary", std::ios::out | std::ios::binary);
  for (int i = 0; i < msg.size(); i++)
    bit_seq = bit_seq + encoder.at(msg[i]);
  //std::bitset<sizeof(unsigned long) * 8> bits(bit_seq);
  //unsigned long binary = bits.to_ulong();
  //f.write((const char*)&binary, sizeof(unsigned long));
  //std::cout << "done" << "\n";
}
