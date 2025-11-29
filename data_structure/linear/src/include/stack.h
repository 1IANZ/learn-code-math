#pragma once
#include "linked_list.h"
class Stack {
  private:
    ListNode* head;
    int size;

  public:
    Stack();
    ~Stack();
    bool push(E value);
    E pop();
    int peek();
    int get_size();
    bool empty();
    static void test();
};