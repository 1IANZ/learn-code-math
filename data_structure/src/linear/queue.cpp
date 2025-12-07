#include "/include/queue.h"

Queue::Queue() {
    front = rear = nullptr;
    size = 0;
}

Queue::~Queue() {
    while (front) {
        ListNode* temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::enqueue(E value) {
    ListNode* newNode = new ListNode(value);
    if (!front) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
    return true;
}

E Queue::dequeue() {
    if (front) {
        E value = front->data;
        ListNode* temp = front;
        front = front->next;
        delete temp;
        size--;
        if (!front)
            rear = nullptr;
        return value;
    } else {
        return -1;
    }
}

int Queue::peek() {
    return front ? front->data : -1;
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
