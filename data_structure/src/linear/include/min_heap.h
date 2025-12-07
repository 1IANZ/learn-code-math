#include <iostream>

class MinHeap {
  private:
    int* data;
    int capacity;
    int size;

    void resize();
    void siftUp(int index);
    void siftDown(int index);

  public:
    MinHeap(int cap = 10);
    ~MinHeap();

    void push(int val);
    int pop();
    int top() const;
    bool empty() const;
    int getSize() const;

    static void test();
};
