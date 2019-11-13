# include <vector>
# include <unordered_map>
# include <queue>
# include "headers/heap_node_def.h"
# include "headers/create_huffman_tree.h"

struct heap_compare {
    bool operator() (heap_node *a, heap_node *b) {
        return (a->freq > b->freq);
    }
};

heap_node* create_huffman_tree(std::unordered_map<int, int> &freq_map) {
    // Push the raw data into the heap
    std::priority_queue<heap_node*, std::vector<heap_node*>, heap_compare> huff_tree;
    std::unordered_map<int, int>::iterator itr;
    for (itr = freq_map.begin(); itr != freq_map.end(); itr++){
        heap_node *curr = new heap_node(itr->first, itr->second);
        huff_tree.push(curr);
    }

    // Iterate till only the root of the huffman tree remains
    while (huff_tree.size() != 1) {
        // Extract the two minimum frequency nodes from heap
        heap_node *left_c = huff_tree.top();
        huff_tree.pop();
        heap_node *right_c = huff_tree.top();
        huff_tree.pop();

        // Create a new parent node with frequency equal
        // to the sum of the two child node frequencies.
        heap_node *parent = new heap_node(0, left_c->freq + right_c->freq);
        parent->left = left_c;
        parent->right = right_c;

        // Push the new node back to the heap
        huff_tree.push(parent);
    }

    return huff_tree.top();
}