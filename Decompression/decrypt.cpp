#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <map>

std::string binary_of_char(char);

int main() {
  std::string temp = ""; // Would be useful to store temporary strings.
  int cnt = 1; // Would be used as a counter when needed.

  // Read the encrypted data and generate the bit stream.
  std::ifstream f("compressed_data.txt");
  std::string binary = "";
  char ch;
  while (f.get(ch)){
    binary = binary + binary_of_char(ch);
  }

  // Read the hashmap that is essential to decrypt the bit stream.
  std::ifstream g("code_map.txt");
  std::map <std::string, int> decoder;
  std::string key = "";
  int value;
  while (g >> temp){
    if (cnt % 2 != 0){
      value = std::stoi(temp);
    }
    else if (cnt % 2 == 0){
      key = temp;
      decoder.insert(std::pair <std::string, int>(key, value));
    }
    cnt++;
  }
  g.close();

  // Read the key which is also essential for decompression.
  std::ifstream h("key.txt");
  int n, choice;
  h >> n;
  h >> choice;
  h.close();

  // Decrypt the bit stream.
  temp = "";
  if (choice == 1){ // Text
    std::cout << "decompressing text..." << "\n" << "\n";
    std::string decompressed_text = "";
    for (int i = 0; i < (binary.size() - n); i++){
      temp = temp + binary[i];
      if (decoder.count(temp)){
        decompressed_text = decompressed_text + char(decoder.at(temp));
        temp = "";
      }
    }
    std::cout << decompressed_text << "\n";
    return 1;
  }

  else if (choice == 2){ // Image
    std::cout << "decompressing Image" << "\n";
    std::vector <int> decompressed_image;
    for (int i = 0; i < (binary.size() - n); i++){
      temp = temp + binary[i];
      if (decoder.count(temp)){
        decompressed_image.push_back(decoder.at(temp));
        temp = "";
      }
    }
    for (int i = 0; i < decompressed_image.size(); i++)
      std::cout << decompressed_image.at(i) << "\n";
  }
  return 2;
}

std::string binary_of_char(char ch) {
    std::bitset<8> temp(ch);
    return temp.to_string();
}
