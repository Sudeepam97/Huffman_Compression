# include <iostream>
# include <unordered_map>
# include <string>
# include <vector>
# include "headers/read_text_file.h"
# include "headers/read_image.h"
# include "headers/heap_node_def.h"
# include "headers/create_huffman_tree.h"
# include "headers/get_codes.h"
# include "headers/compress_data.h"

int main(int argc, char* argv[]){
    std::unordered_map<int, int> freq_map;
    std::vector<int> raw_data;
    switch (*argv[1]) {
        case '1':
            read_text_file(freq_map, raw_data);
            break;
        case '2':
            read_image(freq_map, raw_data);
            break;
        default:
            std::cout << "error: invalid choice: Press '1' to compress text and '2' to compress an image\n";
            return 1;
    }

    // Create the Huffman Tree
    heap_node *root = create_huffman_tree(freq_map);

    // Read codes from the Huffman Tree.
    std::unordered_map<int, std::string> encoder;
    get_codes(root, "", encoder);

    // For debugging
    if (true){
        std::unordered_map<int, std::string>::iterator itr;
        for (itr = encoder.begin(); itr != encoder.end(); itr++){
            std::cout<< (char)(itr->first) << '\t' << itr->second << "\n";
        }
        std::cout << "\n";
    }

    // Perform compression
    std::cout << "Compressing your file. It will take a few moments..." << "\n";
    compress_data(raw_data, encoder, *argv[1]);
    return 0;
}