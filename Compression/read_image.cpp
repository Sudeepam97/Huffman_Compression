#include <fstream>
#include <vector>
#include "headers/read_image.h"

std::vector <int> read_image(){
  std::vector <int> data;
  std::ifstream f("data_to_compress/image.txt");
  int temp = 0;
  while (f >> temp){
    data.push_back(temp);
  }
  return data;
}
