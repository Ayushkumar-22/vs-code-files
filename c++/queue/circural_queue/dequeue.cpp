#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* queue;
    int front, rear, capacity;

public:
    CircularQueue(int size) {
        capacity = size;
        front = rear = 0;
        queue = new int[capacity];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    // Check if the queue is full
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == rear;
    }

    // Enqueue operation
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }
        queue[rear] = item; // Add item at the rear
        rear = (rear + 1) % capacity; // Move rear forward in a circular manner
        cout << "Enqueued " << item << endl;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicate that the queue is empty
        }
        int item = queue[front]; // Get the item to dequeue
        front = (front + 1) % capacity; // Move front forward in a circular manner
        return item; // Return the dequeued item
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5); // Create a circular queue of capacity 5

    // Enqueue some items
    for (int i = 1; i <= 5; i++) {
        q.enqueue(i);
    }

    // Attempt to dequeue items
    for (int i = 0; i < 3; i++) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    // Display remaining queue elements
    q.display();

    return 0;
}
