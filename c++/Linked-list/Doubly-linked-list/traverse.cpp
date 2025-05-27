#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    // take user input for number of nodes
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // create a doubly linked list with n nodes
    Node* head = nullptr;
    Node* prevNode = nullptr;

    for (int i = 0; i < n; i++) {
        // create a new node
        Node* newNode = new Node();

        // take user input for data
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> newNode->data;

        // set the next pointer of the new node to null
        newNode->next = nullptr;

        // set the previous pointer of the new node to the previous node
        newNode->prev = prevNode;

        // if there is a previous node, set its next pointer to the new node
        if (prevNode != nullptr) {
            prevNode->next = newNode;
        } else {
            // if there is no previous node, set the head pointer to the new node
            head = newNode;
        }

        // set the previous node to the new node
        prevNode = newNode;
    }

    // traverse the linked list
    Node* temp = head;
    while (temp != nullptr) {
        // print the data of the current node
        cout << temp->data << " ";

        // move to the next node
        temp = temp->next;
    }
    cout << endl;

    return 0;
}