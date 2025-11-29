#pragma once
#include <iostream>
#define E int
class SeqList {
  private:
    E* data;
    int capacity;
    int size;

  public:
    SeqList(int cap = 10);
    ~SeqList();
    bool insert(int index, E element);
    bool remove(int index);
    int find(E element);
    int get(int index);
    int get_size();
    void display();

    static void test();
};
