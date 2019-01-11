#ifndef NODEDEFINITION_H_
#define NODEDEFINITION_H_

/*
Our aim is to store each unique character/pixel value, along with their
frequency in a list and eventually convert this list into a Huffman tree.
One way to do this is by using a data structure, which is essentially a
doubly linked list in the beginning, but whose nodes are eventually
reconnected to convert the structure into a binary tree.

Due to the nature of Huffman's algorithm, in this "list to tree" transition,
we will encounter a state in which some nodes of our doubly linked list will
act like the roots of the sub-trees of our final Huffman tree. This is why,
each node of our structure should be able to connect as a list, and as a tree
simultaneously.

A structure with the following properties has been defined below.
*/

struct node {
    int data; // The character/pixel value whose huffman code is needed
    int freq;  // The frequency of this character/pixel value
    node *left, *right, *leftc, *rightc;
    /*
    leftc: Pointer to the left child in a binary sub-tree.
    rightc: Pointer to the right child in a binary sub-tree.
    left: Pointer to the the node that is left to the given node in the list.
    right: Pointer to the the node that is right to the given node. */
};

#endif
