#include <iostream>
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
  //std::vector<char> v;
  for (int i = 0; i < message.size(); i++){
    //v.push_back (message[i]);
    /*if (int(message[i]) < 0){
      std::cout << message[i-3] << message[i-2] << message[i-1] << message[i] << message[i+1] << "\n";
    }*/
    text.push_back (int(message[i]));
  }
  /*
  for (int i = 0; i < text.size(); i++){
    std::cout << v.at (i) << "\t" << text.at(i) << "\t" << "\t";
  }*/
  return text;
}
