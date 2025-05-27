#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the queue

class Queue {
private:
    int front, rear, arr[MAX];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
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
            front = 0;
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

    // Change operation to modify an element at a specific index
    void change(int index, int value) {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int size = (rear - front + MAX) % MAX + 1; // Calculate current size
        if (index < 0 || index >= size) {
            cout << "Index out of bounds!" << endl;
            return;
        }
        int actualIndex = (front + index) % MAX;
        arr[actualIndex] = value;
        cout << "Element at index " << index << " changed to " << value << "." << endl;
    }

    // Function to display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % MAX) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl; // Display the rear element
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element is: " << q.peek() << endl; // Peek operation

    q.display();

    // Change element at index 1 (second element)
    q.change(1, 25);
    
    q.display();

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl; // Peek after dequeue

    return 0;
}
