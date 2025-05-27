#include <iostream>
#include <vector>
using namespace std;

class Deque {
private:
    vector<int> dq; // Using vector to store elements

public:
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

    return 0;
}
