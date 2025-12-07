#include <iostream>

#include "huffman.h"

class MinHeapNode {
  private:
    HuffNode** data;
    int capacity;
    int size;
    void siftUp(int);
    void siftDown(int);
    void resize();

  public:
    MinHeapNode(int cap = 10);
    ~MinHeapNode();

    void push(HuffNode* node);
    HuffNode* pop();
    bool empty();
    int getSize();
};
