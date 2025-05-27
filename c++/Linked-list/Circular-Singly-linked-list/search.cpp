#include <iostream>

// Use the standard namespace for input/output
using namespace std;

// Define a struct to represent a node in the linked list
struct Node {
    int data; // Data stored in the node (an integer)
    struct Node *next; // Pointer to the next node in the list
};

int main() {
    // Initialize the head of the linked list to NULL
    Node *head = NULL;

    // Ask the user to enter the number of nodes in the list
    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    // Initialize a pointer to keep track of the last node in the list
    Node *tail = NULL;

    // Create each node in the list and link them together
    for (int i = 0; i < numNodes; i++) {
        // Create a new node
        Node *temp = new Node;

        // Ask the user to enter the data for this node
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> temp->data;

        // Initialize the next pointer of this node to NULL
        temp->next = NULL;

        // If this is the first node, set it as the head and tail
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            // Otherwise, link this node to the previous node
            tail->next = temp;
            tail = temp;
        }
    }

    // Link the last node to the first node to form a circular list
    tail->next = head;

    // Ask the user to enter a key to search for in the list
    int key;
    cout << "Enter the key to search for: ";
    cin >> key;

    // Search for the key in the circular linked list
    Node *temp = head;
    int pos = 1; // Initialize position to 1
    bool found = false;
    do {
        // Check if the current node's data matches the key
        if (temp->data == key) {
            found = true;
            break;
        }
        temp = temp->next;
        pos++; // Increment position
    } while (temp!= head); // Loop until we reach the starting node again

    // Print the result of the search
    if (found) {
        cout << "Element " << key << " found in the circular linked list at position " << pos << "." << endl;
    } else {
        cout << "Element " << key << " not found in the circular linked list." << endl;
    }

    return 0;
}