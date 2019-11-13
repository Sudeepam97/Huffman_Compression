# include <iostream>
# include <vector>
# include <unordered_map>
# include <string>
# include <fstream>
# include <bitset>
# include "headers/heap_node_def.h"
# include "headers/compress_data.h"

void compress_data (std::vector<int> &raw_data, std::unordered_map<int, std::string> &encoder, \
                    char choice) {
    /* Save the (char/pixel --> huffman code) mapping into a file. This mapping
    would be required for decompression and acts as the first part of our key. */
    std::ofstream huff("output/code_map.txt");
    std::unordered_map<int, std::string>::iterator itr;
    for (itr = encoder.begin(); itr != encoder.end(); ++itr){
        huff<< itr->first << '\n' << itr->second << "\n";
    }
    huff.close();

    // Replace chars/pixels with Huffman Codes to generate a bit sequence
    std::string bit_seq = "";
    for (int i = 0; i < raw_data.size(); i++)
        bit_seq = bit_seq + encoder.at(raw_data[i]);

    /* Store the following information in a seperate file:
        a) What has been compressed, text or image?
        b) How many extra_bits bits (for balancing) are present in the bit sequence.
    This information will be necessary for decompression and is like a second key*/
    std::ofstream key("output/key.txt");
    key << create_compressed_file(bit_seq) << "\n" << choice;
    key.close();

    std::cout << "Done. Look inside the directory named 'output'" << "\n";
}

// Create the compressed data file
int create_compressed_file (std::string bit_seq){
    std::string group = "";
    std::ofstream f("output/compressed_data.txt");
    /* We traverse the bit sequence and group 8 bits together to form
    a byte. We then write the character corosponding to this byte into a
    new text file to compress data. */
    for (int i = 0; i < bit_seq.size(); i++){
        group = group + bit_seq[i];
        if (group.size() == 8){
            f << str_to_char(group);
            group = "";
        }
    }
    /* If the number of bits in the bit sequence was not divisible by 8,
    some additional bits may remain which have not been able to form a
    group of 8. Therefore, we add extra bits (all 0s) to adjust this. */
    std::string extra_bits((8 - group.size()), '0');
    f << str_to_char(group + extra_bits);
    f.close();
    /* It is essential to know how many extra bits were
    added to properly decompression our data later on*/
    return (8 - group.size());
}

char str_to_char(std::string group){
    std::bitset<8> temp(group);
    return temp.to_ulong();
}
