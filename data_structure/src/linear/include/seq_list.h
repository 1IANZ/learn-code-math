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
    bool insert(int index, E value);
    bool remove(int index);
    int find(E value);
    int get(int index);
    int get_size();
    void display();

    static void test();
};
