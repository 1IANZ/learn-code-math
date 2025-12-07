#include "include/heap.h"

Heap::Heap(int cap) : capacity(cap), size(0) {
    data = new int[capacity];
}

Heap::~Heap() {
    delete[] data;
}

bool Heap::empty() {
    return size == 0;
}

int Heap::getSize() {
    return size;
}

void Heap::resize() {
    int newCap = capacity * 2;
    int* newData = new int[newCap];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCap;
}

void Heap::siftUp(int index) {
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

void Heap::siftDown(int index) {
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

void Heap::push(int val) {
    if (size == capacity)
        resize();
    data[size] = val;
    siftUp(size);
    size++;
}

int Heap::top() {
    if (empty())
        throw std::runtime_error("Heap is empty");
    return data[0];
}

int Heap::pop() {
    if (empty())
        throw std::runtime_error("Heap is empty");

    int ret = data[0];
    data[0] = data[size - 1];
    size--;
    siftDown(0);

    return ret;
}

void Heap::test() {
    Heap h;

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
