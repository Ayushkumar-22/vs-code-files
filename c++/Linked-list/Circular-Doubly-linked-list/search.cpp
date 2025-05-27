#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

// Define a struct to represent a Node in the circular doubly linked list
struct Node {
    int info; // data stored in the node
    struct Node *next; // pointer to the next node in the list
    struct Node *prev; // pointer to the previous node in the list
};

int main() {
    // Initialize pointers to the start and last nodes of the list
    Node *start = NULL, *last = NULL;
    int count = 0; // count of nodes in the list

    // Get the number of elements to insert into the list
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Insert elements into the list
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;

        // Create a new node with the given value
        Node *temp = new Node;
        temp->info = value;
        temp->next = temp->prev = NULL;

        // Insert the node at the beginning of the list
        if (start == NULL) {
            // If the list is empty, set start and last to the new node
            start = last = temp;
            start->next = last->next = start;
            start->prev = last->prev = start;
        } else {
            // If the list is not empty, insert the node at the beginning
            temp->next = start;
            temp->prev = start->prev;
            start->prev->next = temp;
            start->prev = temp;
            start = temp;
        }
        count++; // increment the count of nodes
    }

    // Display the circular doubly linked list
    cout << "Circular Doubly Linked List: ";
    Node *temp = start;
    do {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp!= start);
    cout << endl;

    // Search for a value in the list
    int search_value;
    cout << "Enter the value to search: ";
    cin >> search_value;

    temp = start;
    int pos = 1;
    do {
        if (temp->info == search_value) {
            // If the value is found, print its position and exit
            cout << search_value << " found at location " << pos << endl;
            return 0;
        }
        temp = temp->next;
        pos++;
    } while (temp!= start);
    // If the value is not found, print a message
    cout << search_value << " not found" << endl;

    return 0;
}