#include <fstream>
#include <vector>
#include "headers/read_text_file.h"

std::vector <int> read_text_file(){
  std::ifstream f("data_to_compress/text_file.txt");
  std::vector<int> data;
  char ch;
  while (f.get(ch)){
    data.push_back (int(ch));
  }
  return data;
}
