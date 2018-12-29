#include <fstream>
#include <string>
#include <vector>
#include "read_text_file.h"

std::vector <int> read_text_file() {
  std::ifstream f;
  std::string message;
  f.open("message.txt");
  f.seekg(0, std::ios::end); // Seek to the last character (0th character from the end of the file).
  int mesg_len = f.tellg();  // Report the location of the seek (equal to the length of message).
  f.seekg(0, std::ios::beg); // Seek to the first character (0th character from the begining of the file).
  message.resize(mesg_len);
  f.read(&message[0], mesg_len);
  f.close();
  std::vector<int> text;
  for (int i = 0; i < message.size(); i++){
    text.push_back (int(message[i]));
  }
  return text;
}
