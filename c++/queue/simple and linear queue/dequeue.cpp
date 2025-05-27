#include <iostream>
using namespace std;

class Queue {
private:
    int* queue;
    int front, rear, capacity;

public:
    Queue(int size) {
        capacity = size;
        front = 0;
        rear = 0;
        queue = new int[capacity];
    }

    ~Queue() {
        delete[] queue;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == capacity;
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
        queue[rear++] = item; // Add item and increment rear
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicate that the queue is empty
        }
        return queue[front++]; // Return item and increment front
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i < rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); // Create a queue of capacity 5

    // Enqueue elements
    for (int i = 1; i <= 5; i++) {
        q.enqueue(i);
        cout << "Enqueued " << i << endl;
        cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;
    }

    // Display queue elements
    q.display();

    // Dequeue elements
    for (int i = 0; i < 3; i++) {
        cout << "Dequeued " << q.dequeue() << endl;
        cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;
    }

    // Display queue elements
    q.display();

    return 0;
}
