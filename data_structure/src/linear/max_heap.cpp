#include "include/max_heap.h"

MaxHeap::MaxHeap(int cap) : capacity(cap), size(0) {
    data = new int[capacity];
}

MaxHeap::~MaxHeap() {
    delete[] data;
}

bool MaxHeap::empty() {
    return size == 0;
}

int MaxHeap::getSize() {
    return size;
}

void MaxHeap::resize() {
    int newCap = capacity * 2;
    int* newData = new int[newCap];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCap;
}

void MaxHeap::siftUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (data[index] > data[parent]) {
            std::swap(data[index], data[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void MaxHeap::siftDown(int index) {
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < size && data[left] > data[largest])
            largest = left;
        if (right < size && data[right] > data[largest])
            largest = right;
        if (largest != index) {
            std::swap(data[index], data[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void MaxHeap::push(int val) {
    if (size == capacity)
        resize();
    data[size] = val;
    siftUp(size);
    size++;
}

int MaxHeap::top() {
    if (empty())
        return -1;
    return data[0];
}

int MaxHeap::pop() {
    if (empty())
        return -1;
    int ret = data[0];
    data[0] = data[size - 1];
    size--;
    siftDown(0);
    return ret;
}

void MaxHeap::test() {
    MaxHeap h;

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
