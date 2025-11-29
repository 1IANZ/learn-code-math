#pragma once
#include "linked_list.h"
class Stack {
  private:
    ListNode* head;
    int size;

  public:
    Stack() : head(nullptr), size(0) {}
    ~Stack() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    bool push(E value);
    E pop();
    int peek();
    int get_size();
    bool empty();
    static void test();
};