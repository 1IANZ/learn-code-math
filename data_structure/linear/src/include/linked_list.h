#pragma once
#include <iostream>
#define E int
using namespace std;

class ListNode {
  public:
    E data;
    ListNode* next;
    ListNode(E val) : data(val), next(nullptr) {}
};

class LinkedList {
  private:
    ListNode* head;
    int size;

  public:
    LinkedList();
    ~LinkedList();

    bool insert(int index, int value);
    bool remove(int index);
    int get(int index);
    int find(int value);
    int get_size();
    void display();

    static void test();
};
