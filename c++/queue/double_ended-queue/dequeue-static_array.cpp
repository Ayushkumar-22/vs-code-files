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

    // Dequeue operation from the front
    int dequeueFront() {
        if (size == 0) {
            cout << "Deque is empty. Cannot dequeue from front." << endl;
            return -1; // Indicate that the deque is empty
        }
        int item = dq[front];
        front = (front + 1) % capacity; // Circular increment
        size--;
        if (size == 0) front = rear = -1; // Reset if deque is empty
        cout << "Dequeued from front: " << item << endl;
        return item;
    }

    // Dequeue operation from the back
    int dequeueBack() {
        if (size == 0) {
            cout << "Deque is empty. Cannot dequeue from back." << endl;
            return -1; // Indicate that the deque is empty
        }
        int item = dq[rear];
        rear = (rear - 1 + capacity) % capacity; // Circular decrement
        size--;
        if (size == 0) front = rear = -1; // Reset if deque is empty
        cout << "Dequeued from back: " << item << endl;
        return item;
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

    // Display the deque elements
    void display() {
        if (size == 0) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int i = 0; i < size; i++) {
            cout << dq[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5); // Create a deque with a capacity of 5

    // Test enqueue operations
    dq.enqueueBack(10);
    dq.enqueueFront(5);
    dq.enqueueBack(20);
    dq.enqueueFront(3);

    // Display current elements
    dq.display();

    // Dequeue some items
    dq.dequeueFront();
    dq.dequeueBack();

    // Display remaining elements
    dq.display();

    return 0;
}
