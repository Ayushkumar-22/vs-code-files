#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, pos, x;

    cout << "Enter the number of elements: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> x;
        Node* new_node = new Node();
        new_node->data = x;
        new_node->next = NULL;

        if(head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    cout << "Enter the position to search: ";
    cin >> pos;

    Node* temp = head;
    int curr_pos = 1;

    while(temp!= NULL) {
        if(curr_pos == pos) {
            cout << "Element at position " << pos << " is " << temp->data;
            return 0;
        }
        temp = temp->next;
        curr_pos++;
    }

    cout << "Position out of range";
    return 0;
}








// - USING POSITION - 



// #include <bits/stdc++.h> // This is a non-standard header file that includes all the standard library headers.
// using namespace std; // This allows us to use standard library functions without prefixing them with std::

// // Define a struct Node to represent a node in the linked list.
// struct Node {
//     int data; // This will store the data of the node.
//     Node* next; // This will store the address of the next node in the list.
// };

// int main() {
//     int n, key, x; // Declare variables to store the number of elements, the key to search, and a temporary variable for input.

//     cout << "Enter the number of elements: "; // Prompt the user to enter the number of elements.
//     cin >> n; // Read the number of elements from the user.

//     Node* head = NULL; // Initialize the head of the linked list to NULL.
//     Node* tail = NULL; // Initialize the tail of the linked list to NULL. This will be used to keep track of the last node in the list.

//     cout << "Enter the elements: "; // Prompt the user to enter the elements.
//     for(int i=0; i<n; i++) { // Loop to read n elements.
//         cin >> x; // Read an element from the user.
//         Node* new_node = new Node(); // Create a new node.
//         new_node->data = x; // Store the element in the new node.
//         new_node->next = NULL; // Set the next pointer of the new node to NULL, indicating it's the last node in the list.

//         if(head == NULL) { // If the list is empty (i.e., head is NULL).
//             head = new_node; // Set the head to the new node.
//             tail = new_node; // Set the tail to the new node.
//         } else { // If the list is not empty.
//             tail->next = new_node; // Add the new node to the end of the list by setting the next pointer of the current tail.
//             tail = new_node; // Update the tail to point to the new node.
//         }
//     }

//     cout << "Enter the key to search: "; // Prompt the user to enter the key to search.
//     cin >> key; // Read the key from the user.

//     Node* temp = head; // Initialize a temporary pointer to the head of the list.
//     int pos = 0; // Initialize a variable to store the position of the key.

//     while(temp != NULL) { // Loop to traverse the linked list.
//         if(temp->data == key) { // Check if the current node's data matches the key.
//             cout << "Search Found at position " << pos; // If found, print the position and exit.
//             return 0;
//         }
//         temp = temp->next; // Move to the next node.
//         pos++; // Increment the position.
//     }

//     cout << "Search Not Found"; // If the key is not found, print this message.
//     return 0;
// }