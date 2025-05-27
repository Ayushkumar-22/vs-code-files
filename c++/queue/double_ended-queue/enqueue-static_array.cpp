#include <iostream>
using namespace std;

class Deque {
private:
    int* dq;         // Pointer to array for storing elements
    int capacity;    // Maximum size of the deque
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int size;        // Current size of the deque

public:
    Deque(int cap) {
        capacity = cap;
        dq = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~Deque() {
        delete[] dq;
    }

    // Enqueue operation at the back
    void enqueueBack(int item) {
        if (size == capacity) {
            cout << "Deque is full. Cannot enqueue at back: " << item << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        dq[rear] = item;
        if (front == -1) front = 0; // First element enqueued
        size++;
        cout << "Enqueued at back: " << item << endl;
    }

    // Enqueue operation at the front
    void enqueueFront(int item) {
        if (size == capacity) {
            cout << "Deque is full. Cannot enqueue at front: " << item << endl;
            return;
        }
        front = (front - 1 + capacity) % capacity; // Circular decrement
        dq[front] = item;
        if (size == 0) rear = front; // First element enqueued
        size++;
        cout << "Enqueued at front: " << item << endl;
    }
};

int main() {
    Deque dq(5); // Create a deque with a capacity of 5

    // Test enqueue operations
    dq.enqueueBack(10);
    dq.enqueueFront(5);
    dq.enqueueBack(20);
    dq.enqueueFront(3);

    return 0;
}
