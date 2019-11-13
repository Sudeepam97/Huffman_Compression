# include <fstream>
# include <unordered_map>
# include <vector>
# include "headers/read_text_file.h"

void read_text_file(std::unordered_map<int, int> &freq_map, std::vector<int> &raw_data){
    std::ifstream f("data_to_compress/text_file.txt");
    char ch;
    while (f.get(ch)){
        raw_data.push_back((int)ch);
        freq_map[int(ch)]++;
    }
}
