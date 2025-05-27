#include <iostream>
using namespace std;

// Define a struct to represent a node in the circular linked list
struct Node {
    int data; // data stored in the node
    struct Node *next; // pointer to the next node in the list
};

// Global variable to store the head of the circular linked list
struct Node* head = NULL;

int main() {
    int n, data, pos, newVal; // variables to store user input

    // Get the number of nodes from the user
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Create and insert nodes into the circular linked list
    for (int i = 0; i < n; i++) {
        // Get the data for the current node from the user
        cout << "Enter the data for node " << i+1 << ": ";
        cin >> data;

        // Create a new node with the given data
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = data;
        newnode->next = head; // initially point to the head of the list

        // If the list is empty, set the new node as the head
        if (head == NULL) {
            head = newnode;
            newnode->next = head; // circular link
        } else {
            // Find the last node in the list
            struct Node *ptr = head;
            while (ptr->next!= head) {
                ptr = ptr->next;
            }

            // Insert the new node at the end of the list
            ptr->next = newnode;
            head = newnode; // update the head to point to the new node
        }
    }

    // Display the original circular linked list
    cout << "The circular linked list is: ";
    struct Node *ptr = head;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr!= head);
    cout << endl;

    // Get the position and new value from the user
    cout << "Enter the position to update: ";
    cin >> pos;
    cout << "Enter the new value: ";
    cin >> newVal;

    // Update the node at the given position
    ptr = head;
    int count = 1;
    while (ptr->next!= head && count < pos) {
        ptr = ptr->next;
        count++;
    }
    if (count == pos) {
        ptr->data = newVal; // update the node data
    } else {
        cout << "Position out of range" << endl;
    }

    // Display the updated circular linked list
    cout << "After updating, the circular linked list is: ";
    ptr = head;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr!= head);
    cout << endl;

    return 0;
}