#ifndef NODEDEFINITION_H_
#define NODEDEFINITION_H_

// Due to the nature of Huffman's algorithm, we need to create an array
// like data structure, where every element of the array is a root of a
// binary tree. These binary trees will essentially be the subtrees of
// our Huffman tree. Since we need the array to be dynamic in nature, we
// must use a linkedlist. The most suitable one for this task would be a
// doubly linkedlist. Hence we create a structure which is essentially a
// hybrid of a binary tree and a doubly linked list.

struct node {
    int data; // The integer which is to be encoded
    int freq;  // The number of times this character appears in the message
    struct node *left, *right, *leftc, *rightc;
    // leftc: Points to the left child of the binary sub-tree.
    // rightc: Points to the right child of the binary sub-tree.
    // left: Points to the address of the node that is left to the given node.
    // right: Points to the address of the node that is right to the given node.
};

#endif
