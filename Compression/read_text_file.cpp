#include <fstream>
#include <unordered_map>
#include "headers/read_text_file.h"

void read_text_file(std::unordered_map<int, int> &raw_data){
  std::ifstream f("data_to_compress/text_file.txt");
  char ch;
  while (f.get(ch))
    raw_data[int(ch)]++;
}
