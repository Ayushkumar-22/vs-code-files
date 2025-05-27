#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the queue

class CircularQueue {
private:
    int front, rear, arr[MAX];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // Initialize front when the first element is added
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        cout << value << " enqueued to queue." << endl;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue." << endl;
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % MAX;
        }
    }

    // Peek operation to view the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Return an invalid value
        }
        return arr[front];
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl; // Display the queue elements
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element is: " << q.peek() << endl; // Peek operation

    q.display();

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl; // Peek after dequeue

    return 0;
}
