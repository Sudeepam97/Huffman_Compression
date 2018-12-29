#include <fstream>
#include <vector>
#include "read_image.h"

std::vector <int> read_image() {
  std::vector <int> data;
  std::ifstream f("image.txt");
  int temp = 0;
  while (f >> temp) {
    data.push_back(temp);
  }
  return data;
}
