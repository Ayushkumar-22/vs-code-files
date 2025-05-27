#include <iostream>

using namespace std;

// Define the Node structure with data, prev, and next pointers
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    // Initialize the head pointer to NULL
    struct Node* head = NULL;

    // Get the number of nodes from the user
    int n, data, key;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Loop through and create each node, linking them together
    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        if (head == NULL) {
            // If this is the first node, create a new node and set head to it
            head = new Node;
            head->data = data;
            head->prev = NULL;
            head->next = NULL;
        } else {
            // Otherwise, find the last node in the list and create a new node after it
            struct Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            struct Node* newNode = new Node;
            newNode->data = data;
            newNode->next = NULL;
            newNode->prev = temp;
            temp->next = newNode;
        }
    }

    // Print the doubly linked list
    cout << "The doubly linked list is: ";
    struct Node* ptr = head;
    int pos = 1;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
        pos++;
    }
    cout << endl;

    // Get the key to search for from the user
    cout << "Enter the key to search: ";
    cin >> key;

    // Loop through the list and search for the key
    ptr = head;
    pos = 1;
    while (ptr != NULL) {
        if (ptr->data == key) {
            // If the key is found, print its position and exit the program
            cout << "Key found in the list at position " << pos << "." << endl;
            return 0;
        }
        ptr = ptr->next;
        pos++;
    }

    // If the key is not found, print an error message
    cout << "Key not found in the list." << endl;
    return 0;
}