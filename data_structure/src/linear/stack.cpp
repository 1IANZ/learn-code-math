#include "include/stack.h"

Stack::Stack() {
    head = nullptr;
    size = 0;
}
Stack::~Stack() {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
};
bool Stack::push(E value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
    size++;
    return true;
}
E Stack::pop() {
    if (head) {
        E value = head->data;
        ListNode* temp = head;
        head = head->next;
        delete temp;
        size--;
        return value;
    } else {
        return -1;
    }
}
int Stack::get_size() {
    return size;
}
E Stack::peek() {
    return head ? head->data : -1;
}
bool Stack::empty() {
    return head == nullptr;
}
void Stack::test() {
    cout << "== Stack Test ==" << endl;
    Stack s;
    cout << "Push: 1, 2, 3" << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Stack size: " << s.get_size() << endl;
    cout << "Top element: " << s.peek() << endl;
    cout << "Pop element: " << s.pop() << endl;
    cout << "Top element after pop: " << s.peek() << endl;
    cout << "Stack size after pop: " << s.get_size() << endl;
    cout << "Pop all elements..." << endl;
    while (!s.empty())
        cout << s.pop() << " ";
    cout << endl;
}