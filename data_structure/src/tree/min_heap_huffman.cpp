#include "include/min_heap_huffman.h"

MinHeapNode::MinHeapNode(int cap) : capacity(cap), size(0) {
    data = new HuffNode*[capacity];
}

MinHeapNode::~MinHeapNode() {
    delete[] data;
}

bool MinHeapNode::empty() {
    return size == 0;
}

int MinHeapNode::getSize() {
    return size;
}

void MinHeapNode::resize() {
    int newCap = capacity * 2;
    HuffNode** newData = new HuffNode*[newCap];

    for (int i = 0; i < size; i++)
        newData[i] = data[i];

    delete[] data;
    data = newData;
    capacity = newCap;
}

void MinHeapNode::siftUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (data[index]->freq < data[parent]->freq) {
            std::swap(data[index], data[parent]);
            index = parent;
        } else
            break;
    }
}

void MinHeapNode::siftDown(int index) {
    while (true) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int smallest = index;

        if (left < size && data[left]->freq < data[smallest]->freq)
            smallest = left;
        if (right < size && data[right]->freq < data[smallest]->freq)
            smallest = right;

        if (smallest != index) {
            std::swap(data[index], data[smallest]);
            index = smallest;
        } else
            break;
    }
}

void MinHeapNode::push(HuffNode* node) {
    if (size == capacity)
        resize();

    data[size] = node;
    siftUp(size);
    size++;
}

HuffNode* MinHeapNode::pop() {
    if (empty())
        return nullptr;

    HuffNode* ret = data[0];
    data[0] = data[size - 1];
    size--;

    siftDown(0);
    return ret;
}
