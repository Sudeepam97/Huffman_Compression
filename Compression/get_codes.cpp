#include <string>
#include <unordered_map>
#include "headers/heap_node_def.h"
#include "headers/get_codes.h"

void get_codes(heap_node* root, std::string code, std::unordered_map<int, std::string> &encoder) {
    if (!root->left && !root->right){
        encoder[root->data] = code;
        return;
    }
    get_codes(root->left, code + '0', encoder);
    get_codes(root->right, code + '1', encoder);
}