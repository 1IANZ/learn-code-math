#include "include/linked_list.h"

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    ListNode* cur = head;
    while (cur) {
        ListNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

bool LinkedList::insert(int index, int value) {
    if (index < 0 || index > size)
        return false;

    ListNode* newNode = new ListNode(value);

    if (index == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        ListNode* cur = head;
        for (int i = 0; i < index - 1; i++)
            cur = cur->next;
        newNode->next = cur->next;
        cur->next = newNode;
    }

    size++;
    return true;
}

bool LinkedList::remove(int index) {
    if (index < 0 || index >= size)
        return false;

    ListNode* delListNode;
    if (index == 0) {
        delListNode = head;
        head = head->next;
    } else {
        ListNode* cur = head;
        for (int i = 0; i < index - 1; i++)
            cur = cur->next;
        delListNode = cur->next;
        cur->next = delListNode->next;
    }

    delete delListNode;
    size--;
    return true;
}

int LinkedList::get(int index) {
    if (index < 0 || index >= size)
        return -1;

    ListNode* cur = head;
    for (int i = 0; i < index; i++)
        cur = cur->next;

    return cur->data;
}

int LinkedList::find(int value) {
    ListNode* cur = head;
    for (int i = 0; i < size; i++) {
        if (cur->data == value)
            return i;
        cur = cur->next;
    }
    return -1;
}

int LinkedList::get_size() {
    return size;
}

void LinkedList::display() {
    ListNode* cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void LinkedList::test() {
    cout << " == Linked List == " << endl;
    LinkedList list;
    for (int i = 1; i <= 5; i++)
        list.insert(list.get_size(), i);
    cout << "init list: ";
    list.display();
    list.insert(2, 6);
    cout << "insert 6 at index 2: ";
    list.display();
    list.remove(4);
    cout << "remove element at index 4: ";
    list.display();
    int pos = list.find(3);
    cout << "index of element 3: " << pos << endl;
    cout << "element at index 1: " << list.get(1) << endl;
}
