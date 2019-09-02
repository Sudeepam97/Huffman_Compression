#ifndef HEAPNODEDEF_H_
#define HEAPNODEDEF_H_

struct heap_node {
  int data;
  int freq;
  heap_node *left, *right;

  heap_node(int data, int freq) { 
    this->data = data;
    this->freq = freq;
    left = right = NULL; 
  }
};

#endif
