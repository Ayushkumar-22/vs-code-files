#include <iostream>

using namespace std;

// Define a struct to represent a node in the linked list
struct Node {
    int data; // The data stored in the node
    Node* next; // A pointer to the next node in the list
};

int main() {
    // Create a pointer to the head of the linked list
    Node* head = NULL;
    int n, num;

    // Ask the user for the number of elements in the list
    cout << "Enter the number of elements: ";
    cin >> n;

    // Create the linked list by inserting nodes at the beginning
    Node* tail = NULL;
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> num;
        Node* newNode = new Node();
        newNode->data = num;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print the original order of elements
    cout << "Original order of elements: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Sort the linked list using insertion sort
    Node* current = head;
    Node* sorted = NULL;

    // Make the list empty by moving nodes to the sorted list
    while (current != NULL) {
        Node* next = current->next;
        Node* temp = sorted;

        // Find the correct position for the current node in the sorted list
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
            head = sorted;
        } else {
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    // Print the linked list after sorting
    cout << "Linked List after sorting: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}