#include <iostream>

using namespace std;

// Define a struct to represent a node in the circular doubly linked list
struct Node {
    int data; // data stored in the node
    Node* next; // pointer to the next node in the list
    Node* prev; // pointer to the previous node in the list
};

int main() {
    // Initialize pointers to the head and tail of the list
    Node* head = NULL;
    Node* tail = NULL;

    // Ask the user to enter the number of nodes in the list
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    // Loop to create each node in the list
    for (int i = 0; i < numNodes; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        // Create a new node and initialize its data and pointers
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head; // initially, next points to the head of the list
        newNode->prev = tail; // initially, prev points to the tail of the list

        // If the list is empty, set the head and tail to the new node
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            // Otherwise, update the next and prev pointers of the tail and head nodes
            tail->next = newNode;
            head->prev = newNode;
        }

        // Update the tail pointer to point to the new node
        tail = newNode;
    }

    // Traverse the list in forward direction
    Node* temp = head;
    cout << "Forward traversal: ";
    do {
        cout << temp->data << " "; // print the data of the current node
        temp = temp->next; // move to the next node
    } while (temp!= head); // loop until we reach the head node again
    cout << endl;

    // Traverse the list in backward direction
    temp = tail;
    cout << "Backward traversal: ";
    do {
        cout << temp->data << " "; // print the data of the current node
        temp = temp->prev; // move to the previous node
    } while (temp!= tail); // loop until we reach the tail node again
    cout << endl;

    return 0;
}