#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;     // Data stored in the node
    Node* next;   // Pointer to the next node in the list
};

int main() {
    // Initialize the head of the list to null
    Node* head = nullptr;

    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    // Loop through the number of nodes the user wants to create
    for (int i = 0; i < numNodes; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        // If this is the first node, set the head to point to it
        if (head == nullptr) {
            head = new Node(); // Allocate memory for a new node
            head->data = data; // Set data for the head node
            head->next = nullptr;  // Since it's the only node, the next pointer is null
        } else {
            // Otherwise, traverse the list until we reach the end
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }

            // Insert the new node at the end of the list
            current->next = new Node();     // Allocate memory for the new node
            current->next->data = data;     // Set data for the new node
            current->next->next = nullptr;  // Next pointer of the new node is null since it's the last node
        }
    }

    // Traverse the list and print the data values of each node
    cout << "Linked list: ";
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data << " ";
    }
    cout << endl;

    // The program ends here
    return 0;
}