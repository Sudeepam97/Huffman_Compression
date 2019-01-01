#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <map>

std::string binary_of_char(char);

int main() {
  std::string temp = ""; // Would be useful to store temporary srtings.
  int cnt = 1; // Would be used as a counter when needed.

  // Read the encrypted data.
  std::ifstream f("data.txt");
  std::string encrypted_data;
  f.seekg(0, std::ios::end); // Seek to the last character (0th character from the end of the file).
  int mesg_len = f.tellg();  // Report the location of the seek (equal to the length of encrypted_data).
  f.seekg(0, std::ios::beg); // Seek to the first character (0th character from the begining of the file).
  encrypted_data.resize(mesg_len);
  f.read(&encrypted_data[0], mesg_len);
  f.close();

  // Generate the bit stream from the encrypted message.
  std::string binary = "";
  for (int i = 0; i < encrypted_data.size(); i++){
    binary = binary + binary_of_char(encrypted_data[i]);
  }

  // Read the hashmap that is essential to decrypt the bit stream.
  std::ifstream g("decryption_map.txt");
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
      //std::cout << value << "\n" << key << "\n";
    }
    cnt++;
  }
  g.close();

  // Extract header information
  std::ifstream h("header.txt");
  int n, choice;
  h >> n;
  h >> choice;
  h.close();


  // Decrypt the bit stream.
  temp = "";
  // Text
  if (choice == 1) {
    std::cout << "decompressing text" << "\n";
    std::string decoded_text = "";
    for (int i = 0; i < (binary.size() - n); i++){
      temp = temp + binary[i];
      if (decoder.count(temp)){
        decoded_text = decoded_text + char(decoder.at(temp));
        temp = "";
      }
    }
    std::cout << decoded_text << "\n";
  }
  // Image
  else if (choice == 2){
    std::cout << "decompressing Image" << "\n";
    std::vector <int> decoded_image;
    for (int i = 0; i < (binary.size() - n); i++){
      temp = temp + binary[i];
      if (decoder.count(temp)){
        decoded_image.push_back(decoder.at(temp));
        temp = "";
      }
    }
    for (int i = 0; i < decoded_image.size(); i++)
      std::cout << decoded_image.at(i) << "\n";
  }
  return 1;
}

std::string binary_of_char(char ch) {
    std::bitset<8> temp(ch);
    return temp.to_string();
}
