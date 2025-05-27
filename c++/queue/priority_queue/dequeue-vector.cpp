#include <iostream>
#include <vector>
#include <algorithm> // Include this for lower_bound
using namespace std;

class PriorityQueue {
private:
    vector<int> queue;

public:
    // Enqueue operation
    void enqueue(int item) {
        // Insert the item in sorted order
        auto it = lower_bound(queue.begin(), queue.end(), item, greater<int>());
        queue.insert(it, item);
        cout << "Enqueued: " << item << endl;
    }

    // Dequeue operation (to remove the highest priority item)
    int dequeue() {
        if (queue.empty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Indicate that the queue is empty
        }
        int item = queue.front(); // Get the highest priority item
        queue.erase(queue.begin()); // Remove the highest priority item
        cout << "Dequeued: " << item << endl;
        return item;
    }

    // Display the priority queue
    void display() {
        if (queue.empty()) {
            cout << "Priority Queue is empty." << endl;
            return;
        }
        cout << "Priority Queue elements: ";
        for (int item : queue) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    // Test enqueue operation
    pq.enqueue(10);
    pq.enqueue(5);
    pq.enqueue(30);
    pq.enqueue(20);
    pq.enqueue(15);

    // Display current elements
    pq.display();

    // Dequeue some items
    pq.dequeue();
    pq.dequeue();

    // Display remaining elements
    pq.display();

    return 0;
}
