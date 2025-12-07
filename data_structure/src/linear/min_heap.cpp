#include "include/min_heap.h"

MinHeap::MinHeap(int cap) : capacity(cap), size(0) {
    data = new int[capacity];
}

MinHeap::~MinHeap() {
    delete[] data;
}

bool MinHeap::empty() const {
    return size == 0;
}

int MinHeap::getSize() const {
    return size;
}

int MinHeap::top() const {
    if (empty()) {
        std::cout << "Heap is empty!\n";
        return -1;
    }
    return data[0];
}

void MinHeap::resize() {
    int newCap = capacity * 2;
    int* newData = new int[newCap];

    for (int i = 0; i < size; i++)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity = newCap;
}

void MinHeap::siftUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (data[index] < data[parent]) {
            std::swap(data[index], data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void MinHeap::siftDown(int index) {
    while (true) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        int smallest = index;

        if (left < size && data[left] < data[smallest])
            smallest = left;

        if (right < size && data[right] < data[smallest])
            smallest = right;

        if (smallest != index) {
            std::swap(data[index], data[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void MinHeap::push(int val) {
    if (size == capacity)
        resize();

    data[size] = val;
    siftUp(size);
    size++;
}

int MinHeap::pop() {
    if (empty()) {
        std::cout << "Heap is empty!\n";
        return -1;
    }

    int rootValue = data[0];
    data[0] = data[size - 1];
    size--;

    siftDown(0);

    return rootValue;
}

void MinHeap::test() {
    MinHeap h;

    std::cout << "Pushing: 30 20 40 10 50\n";
    h.push(30);
    h.push(20);
    h.push(40);
    h.push(10);
    h.push(50);

    std::cout << "Current top(): " << h.top() << "\n";
    std::cout << "Pop order: ";
    while (!h.empty()) {
        std::cout << h.pop() << " ";
    }
    std::cout << "\n";
}
