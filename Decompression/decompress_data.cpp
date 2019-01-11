#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <unordered_map>

std::string binary_of_char(char);

int main(){
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
  std::unordered_map <std::string, int> decoder;
  std::string key = "";
  int value;
  while (g >> temp){
    if (cnt % 2 != 0){
      value = std::stoi(temp);
    }
    else if (cnt % 2 == 0){
      key = temp;
      decoder[key] = value;
    }
    cnt++;
  }
  g.close();

  // Read the key which is also essential for decompression.
  std::ifstream k("key.txt");
  int n, choice;
  k >> n;
  k >> choice;
  k.close();

  // Decrypt the bit stream.
  temp = "";
  std::ofstream out("decompressed_data.txt");

  // For Text
  if (choice == 1){
    std::cout << "decompressing Text...";
    std::string decompressed_text = "";
    for (int i = 0; i < (binary.size() - n); i++){
      temp = temp + binary[i];
      if (decoder.count(temp)){
        decompressed_text = decompressed_text + char(decoder.at(temp));
        temp = "";
      }
    }
    out << decompressed_text;
    std::cout << "DONE" << '\n';
  }

  // For Image
  else if (choice == 2){
    std::cout << "decompressing Image...";
    for (int i = 0; i < (binary.size() - n); i++){
      temp = temp + binary[i];
      if (decoder.count(temp)){
        out << decoder.at(temp) << "\n";
        temp = "";
      }
    }
    std::cout << "DONE" << '\n';
  }
  return 0;
}

std::string binary_of_char(char ch){
    std::bitset<8> temp(ch);
    return temp.to_string();
}
