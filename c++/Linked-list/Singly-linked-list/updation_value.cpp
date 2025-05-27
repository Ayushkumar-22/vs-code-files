#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data; // data stored in the node
    Node* next; // pointer to the next node in the list
};

int main() {
    // Create a linked list
    Node* head = nullptr; // head of the list, initially set to nullptr
    int numElements;
    cout << "Enter the number of elements in the list: ";
    cin >> numElements;

    // Loop to create and add nodes to the list
    for (int i = 0; i < numElements; i++) {
        int element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;

        // Create a new node with the entered element
        Node* newNode = new Node{element, nullptr};

        // If the list is empty, set the head to the new node
        if (head == nullptr) {
            head = newNode;
        } else {
            // Otherwise, find the last node in the list and add the new node to it
            Node* current = head;
            while (current->next!= nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Print the original list
    cout << "Original list: ";
    Node* current = head;
    while (current!= nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Update an element in the list
    int oldValue, newValue;
    cout << "Enter the old value to update: ";
    cin >> oldValue;
    cout << "Enter the new value: ";
    cin >> newValue;

    // Loop to find and update the element
    current = head;
    while (current!= nullptr) {
        if (current->data == oldValue) {
            // If the element is found, update its value and exit the loop
            current->data = newValue;
            break;
        }
        current = current->next;
    }
    if (current == nullptr) {
        // If the element is not found, print a message
        cout << "Element not found in the list." << endl;
    }

    // Print the updated list
    cout << "Updated list: ";
    current = head;
    while (current!= nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}



// USING POSITION - 


/*
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

int main() {
    // Create a linked list
    Node* head = nullptr;
    int numElements;
    cout << "Enter the number of elements in the list: ";
    cin >> numElements;

    for (int i = 0; i < numElements; i++) {
        int element;
        cout << "Enter element " << i + 1 << ": ";
        cin >> element;

        Node* newNode = new Node{element, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    cout << "Original list: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Update an element in the list
    int position, newValue;
    cout << "Enter the position to update: ";
    cin >> position;
    cout << "Enter the new value: ";
    cin >> newValue;

    if (position <= 0 || position > numElements) {
        cout << "Invalid position." << endl;
        return 1;
    }

    if (position == 1) {
        head->data = newValue;
    } else {
        current = head;
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        current->next->data = newValue;
    }

    cout << "Updated list: ";
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
*/