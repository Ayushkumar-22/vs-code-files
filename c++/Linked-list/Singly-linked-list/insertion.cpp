#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    // Declare a head pointer to the head of the list
    Node* head = nullptr;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Loop to create n nodes
    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        // If it's the first node, initialize the head pointer
        if (i == 0) {
            head = new Node();
            head->data = data;
            head->next = nullptr;
        } else {
            // Traverse the list to find the last node
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // Append the new node to the end of the list
            current->next = new Node();
            current->next->data = data;
            current->next->next = nullptr;
        }
    }

    cout << "Linked list: ";
    // Print the linked list
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    int pos, data;
    cout << "Enter position to insert new node: ";
    cin >> pos;
    cout << "Enter data for new node: ";
    cin >> data;

    // If the position is 0, insert the new node at the beginning of the list
    if (pos == 0) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    } else {
        // Traverse the list to find the node at position pos - 1
        Node* current = head;
        int count = 0;
        while (current != nullptr && count < pos - 1) {
            current = current->next;
            count++;
        }

        // If the position is out of range, print an error message and return
        if (current == nullptr) {
            cout << "Position out of range" << endl;
            return 1;
        }

        // Insert the new node after the node at position pos - 1
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;
    }

    cout << "Linked list after insertion: ";
    // Print the linked list after the insertion
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}