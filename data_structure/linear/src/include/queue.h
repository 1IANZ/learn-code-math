#pragma once
#include "linked_list.h"

#define E int
class Queue {
  private:
    ListNode* head;
    int size;

  public:
    Queue();
    ~Queue();
    bool enqueue(E value);
    E dequeue();
    int peek();
    int get_size();
    bool empty();
    static void test();
};