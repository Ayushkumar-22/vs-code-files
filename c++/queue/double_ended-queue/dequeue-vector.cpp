#include <iostream>
#include <vector>
using namespace std;

class Deque {
private:
    vector<int> dq; // Using vector to store elements

public:
    // Dequeue operation from the front
    int dequeueFront() {
        if (dq.empty()) {
            cout << "Deque is empty. Cannot dequeue from front." << endl;
            return -1; // Indicate that the deque is empty
        }
        int item = dq.front();
        dq.erase(dq.begin()); // Remove the first element
        cout << "Dequeued from front: " << item << endl;
        return item;
    }

    // Dequeue operation from the back
    int dequeueBack() {
        if (dq.empty()) {
            cout << "Deque is empty. Cannot dequeue from back." << endl;
            return -1; // Indicate that the deque is empty
        }
        int item = dq.back();
        dq.pop_back(); // Remove the last element
        cout << "Dequeued from back: " << item << endl;
        return item;
    }

    // Enqueue operation at the back
    void enqueueBack(int item) {
        dq.push_back(item);
        cout << "Enqueued at back: " << item << endl;
    }

    // Enqueue operation at the front
    void enqueueFront(int item) {
        dq.insert(dq.begin(), item);
        cout << "Enqueued at front: " << item << endl;
    }

    // Display the deque elements
    void display() {
        if (dq.empty()) {
            cout << "Deque is empty." << endl;
            return;
        }
        cout << "Deque elements: ";
        for (int item : dq) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

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
