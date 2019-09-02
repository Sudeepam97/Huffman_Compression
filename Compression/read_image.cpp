#include <fstream>
#include <unordered_map>
#include "headers/read_image.h"

void read_image(std::unordered_map<int, int> &raw_data){
  std::ifstream f("data_to_compress/image.txt");
  int temp = 0;
  while (f >> temp)
    raw_data[temp]++;
}