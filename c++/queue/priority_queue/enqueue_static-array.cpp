
#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int* queue;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        queue = new int[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] queue;
    }

    // Enqueue operation
    void enqueue(int item) {
        if (size >= capacity) {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }

        // Find the position to insert the item
        int i;
        for (i = size - 1; (i >= 0 && queue[i] < item); i--) {
            queue[i + 1] = queue[i]; // Shift elements to the right
        }
        queue[i + 1] = item; // Insert the item
        size++;
        cout << "Enqueued: " << item << endl;
    }

    // Dequeue operation
    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicate that the queue is empty
        }
        int item = queue[0]; // Get the highest priority item
        for (int i = 0; i < size - 1; i++) {
            queue[i] = queue[i + 1]; // Shift elements to the left
        }
        size--; // Reduce the size
        cout << "Dequeued: " << item << endl;
        return item;
    }

    // Display the priority queue
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty." << endl;
            return;
        }
        cout << "Priority Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(5); // Create a priority queue with a capacity of 5

    // Test enqueue operation
    pq.enqueue(10);
    pq.enqueue(5);
    pq.enqueue(30);
    pq.enqueue(20);
    pq.enqueue(15);

    // Attempt to enqueue one more item
    pq.enqueue(25);

    // Display current elements
    pq.display();

    // Dequeue some items
    pq.dequeue();
    pq.dequeue();

    // Display remaining elements
    pq.display();

    return 0;
}
