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

    // For testing, we can implement dequeue
    int dequeue() {
        if (front == rear) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicate that the queue is empty
        }
        int item = queue[front]; // Get the item to dequeue
        front = (front + 1) % capacity; // Move front forward in a circular manner
        return item;
    }
};

int main() {
    CircularQueue q(5); // Create a circular queue of capacity 5

    // Test enqueue operation
    for (int i = 1; i <= 5; i++) {
        q.enqueue(i);
    }
    
    // Attempt to enqueue one more item
    q.enqueue(6);

    return 0;
}
