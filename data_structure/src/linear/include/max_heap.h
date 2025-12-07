#include <iostream>

class MaxHeap {
  private:
    int* data;
    int capacity;
    int size;

    void resize();
    void siftUp(int index);
    void siftDown(int index);

  public:
    MaxHeap(int cap = 10);
    ~MaxHeap();
    void push(int val);
    int top();
    int pop();
    bool empty();
    int getSize();

    static void test();
};
