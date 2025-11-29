#include "/include/queue.h"

Queue::Queue() {
    head = nullptr;
    size = 0;
}

Queue::~Queue() {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

bool Queue::enqueue(E value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
    return true;
}

E Queue::dequeue() {
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

int Queue::peek() {
    return head ? head->data : -1;
}

int Queue::get_size() {
    return size;
}

bool Queue::empty() {
    return size == 0;
}

void Queue::test() {
    cout << "== Queue Test ==" << endl;
    Queue q;
    cout << "Enqueue: 1, 2, 3" << endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Queue size: " << q.get_size() << endl;
    cout << "Front element: " << q.peek() << endl;
    cout << "Dequeue element: " << q.dequeue() << endl;
    cout << "Front element after dequeue: " << q.peek() << endl;
    cout << "Queue size after dequeue: " << q.get_size() << endl;
    cout << "Dequeue all elements..." << endl;
    while (!q.empty())
        cout << q.dequeue() << " ";
    cout << endl;
}