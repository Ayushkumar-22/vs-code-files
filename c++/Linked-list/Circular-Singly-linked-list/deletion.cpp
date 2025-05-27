#include <iostream>
using namespace std;

// Define a struct to represent a node in the circular singly linked list
struct Node {
    int data; // data stored in the node
    Node* next; // pointer to the next node in the list
};

int main() {
    Node* head = NULL; // initialize the head of the list to NULL

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Create a circular singly linked list
    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        Node* newNode = new Node; // create a new node
        newNode->data = data; // set the data of the new node

        if (head == NULL) {
            head = newNode; // if the list is empty, set the head to the new node
            newNode->next = head; // set the next pointer of the new node to the head (circular link)
        } else {
            Node* temp = head;
            while (temp->next != head) { // traverse the list to find the last node
                temp = temp->next;
            }
            temp->next = newNode; // set the next pointer of the last node to the new node
            newNode->next = head; // set the next pointer of the new node to the head (circular link)
        }
    }

    // Display the circular linked list
    cout << "The circular linked list is: ";
    Node* temp = head;
    do {
        cout << temp->data << " "; // print the data of each node
        temp = temp->next; // move to the next node
    } while (temp != head); // loop until we reach the head again
    cout << endl;

    int key;
    cout << "Enter the node value to be deleted: ";
    cin >> key;

    // Delete a node from the circular linked list
    if (head == NULL) {
        cout << "List is empty" << endl;
        return 0;
    }

    Node* curr = head; // current node
    Node* prev = head; // previous node

    // Find the node to be deleted
    while (curr->next != head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is the head node
    if (curr->data == key && curr == head) {
        if (head->next == head) {
            head = NULL; // if the list has only one node, set the head to NULL
            free(curr); // deallocate the memory of the node
            cout << "Node deleted successfully" << endl;
        } else {
            Node* temp = head;
            while (temp->next != head) { // traverse the list to find the last node
                temp = temp->next;
            }

            temp->next = head->next; // update the next pointer of the last node
            head = head->next; // update the head to the next node
            free(curr); // deallocate the memory of the node
            cout << "Node deleted successfully" << endl;
        }
    }

    // If the node to be deleted is not the head node
    else if (curr->data == key) {
        prev->next = curr->next; // update the next pointer of the previous node
        free(curr); // deallocate the memory of the node
        cout << "Node deleted successfully" << endl;
    } else {
        cout << "Node not found" << endl;
    }

    // Display the circular linked list after deletion
    cout << "The circular linked list after deletion is: ";
    temp = head;
    if (head != NULL) {
        do {
            cout << temp->data << " "; // print the data of each node
            temp = temp->next; // move to the next node
        } while (temp != head); // loop until we reach the head again
        cout << endl;
    } else {
        cout << "List is empty" << endl;
    }

    return 0;
}




// DELETION BASED ON THE POSITION



// #include <iostream>
// using namespace std;

// // Define a struct to represent a node in the circular singly linked list
// struct Node {
//     int data; // data stored in the node
//     Node* next; // pointer to the next node in the list
// };

// int main() {
//     Node* head = NULL; // initialize the head of the list to NULL

//     int n;
//     cout << "Enter the number of nodes: ";
//     cin >> n;

//     // Create a circular singly linked list
//     for (int i = 0; i < n; i++) {
//         int data;
//         cout << "Enter data for node " << i + 1 << ": ";
//         cin >> data;

//         Node* newNode = new Node; // create a new node
//         newNode->data = data; // set the data of the new node

//         if (head == NULL) {
//             head = newNode; // if the list is empty, set the head to the new node
//             newNode->next = head; // set the next pointer of the new node to the head (circular link)
//         } else {
//             Node* temp = head;
//             while (temp->next != head) { // traverse the list to find the last node
//                 temp = temp->next;
//             }
//             temp->next = newNode; // set the next pointer of the last node to the new node
//             newNode->next = head; // set the next pointer of the new node to the head (circular link)
//         }
//     }

//     // Display the circular linked list
//     cout << "The circular linked list is: ";
//     Node* temp = head;
//     do {
//         cout << temp->data << " "; // print the data of each node
//         temp = temp->next; // move to the next node
//     } while (temp != head); // loop until we reach the head again
//     cout << endl;

//     int pos;
//     cout << "Enter the position of the node to be deleted: ";
//     cin >> pos;

//     // Delete a node from the circular linked list based on position
//     if (head == NULL) {
//         cout << "List is empty" << endl;
//         return 0;
//     }

//     Node* curr = head; // current node
//     Node* prev = head; // previous node

//     // Find the node to be deleted
//     int count = 1;
//     while (count < pos && curr->next != head) {
//         prev = curr;
//         curr = curr->next;
//         count++;
//     }

//     // If the node to be deleted is the head node
//     if (pos == 1) {
//         if (head->next == head) {
//             head = NULL; // if the list has only one node, set the head to NULL
//             free(curr); // deallocate the memory of the node
//             cout << "Node deleted successfully" << endl;
//         } else {
//             Node* temp = head;
//             while (temp->next != head) { // traverse the list to find the last node
//                 temp = temp->next;
//             }

//             temp->next = head->next; // update the next pointer of the last node
//             head = head->next; // update the head to the next node
//             free(curr); // deallocate the memory of the node
//             cout << "Node deleted successfully" << endl;
//         }
//     }

//     // If the node to be deleted is not the head node
//     else if (count == pos) {
//         prev->next = curr->next; // update the next pointer of the previous node
//         free(curr); // deallocate the memory of the node
//         cout << "Node deleted successfully" << endl;
//     } else {
//         cout << "Position out of range" << endl;
//     }

//     // Display the circular linked list after deletion
//     cout << "The circular linked list after deletion is: ";
//     temp = head;
//     if (head != NULL) {
//         do {
//             cout << temp->data << " "; // print the data of each node
//             temp = temp->next; // move to the next node
//         } while (temp != head); // loop until we reach the head again
//         cout << endl;
//     } else {
//         cout << "List is empty" << endl;
//     }

//     return 0;
// }