#include <iostream>

class Heap {
  private:
    int* data;
    int capacity;
    int size;

    void resize();
    void siftUp(int index);
    void siftDown(int index);

  public:
    Heap(int cap = 10);
    ~Heap();
    void push(int val);
    int top();
    int pop();
    bool empty();
    int getSize();

    static void test();
};
