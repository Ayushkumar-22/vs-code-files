#include <iostream>
using namespace std;

class Queue {
private:
    int* queue;
    int rear, capacity;

public:
    Queue(int size) {
        capacity = size;
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

    // Enqueue operation
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }
        queue[rear++] = item; // Add item and increment rear
        cout << "Enqueued " << item << endl;
    }
};

int main() {
    Queue q(5); // Create a queue of capacity 5

    // Test enqueue operation
    for (int i = 1; i <= 6; i++) { // Try to enqueue 6 items
        q.enqueue(i);
    }

    return 0;
}
