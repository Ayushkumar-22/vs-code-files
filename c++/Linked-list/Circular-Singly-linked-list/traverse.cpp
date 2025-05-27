#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Ask the user for the number of nodes in the list
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    // Create the head node and the current node pointer
    Node* head = nullptr;
    Node* temp = nullptr;

    // Loop through the number of nodes
    for(int i=0; i<n; i++) {
        // If it's the first node, create it and set it as the head
        if(i == 0) {
            head = new Node();
            temp = head;
        } else {
            // Otherwise, create a new node and set it as the next node for the current node
            temp->next = new Node();
            temp = temp->next;
        }
        // Ask the user for the data for the current node
        cout << "Enter value for node " << i+1 << ": ";
        cin >> temp->data;
    }
    // Set the next node of the last node to the head node to make it a circular list
    temp->next = head;

    // Print the circular linked list
    cout << "Circular linked list: ";
    temp = head;
    // Loop through the list until the current node is the head node again
    do {
        // Print the data of the current node
        cout << temp->data << " -> ";
        // Move to the next node
        temp = temp->next;
    } while(temp!= head);
    // Print "NULL" to indicate the end of the list
    cout << "NULL" << endl;

    return 0;
}