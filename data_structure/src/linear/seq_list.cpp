#include "include/seq_list.h"

using namespace std;

SeqList::SeqList(int cap) {
    data = new E[cap];
    capacity = cap;
    size = 0;
}

SeqList::~SeqList() {
    delete[] data;
}

bool SeqList::insert(int index, E value) {
    if (index < 0 || index > size)
        return false;
    if (size >= capacity) {
        int* newData = new int[capacity * 2];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity *= 2;
    }
    for (int i = size; i > index; i--)
        data[i] = data[i - 1];
    data[index] = value;
    size++;
    return true;
}

bool SeqList::remove(int index) {
    if (index < 0 || index >= size)
        return false;
    for (int i = index; i < size - 1; i++)
        data[i] = data[i + 1];
    size--;
    return true;
}

int SeqList::find(E element) {
    for (int i = 0; i < size; i++)
        if (data[i] == element)
            return i;
    return -1;
}

int SeqList::get(int index) {
    if (index < 0 || index >= size)
        return -1;
    return data[index];
}

int SeqList::get_size() {
    return size;
}

void SeqList::display() {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
}

void SeqList::test() {
    cout << " == Sequence List == " << endl;
    SeqList list;
    for (int i : {1, 2, 3, 4, 5})
        list.insert(list.get_size(), i);
    cout << "init list: ";
    list.display();
    list.insert(2, 6);
    cout << "Insert 6 at index 2: ";
    list.display();
    list.remove(4);
    cout << "Remove element at index 4: ";
    list.display();
    int pos = list.find(2);
    if (pos != -1)
        cout << "Index of element 2: " << pos << endl;
    else
        cout << "not found 2 " << endl;
    cout << "Element of index 4: " << list.get(4) << endl;
}
