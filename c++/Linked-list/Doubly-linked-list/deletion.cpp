#include<iostream> // Include the input/output stream library for C++
using namespace std;

// Node structure
struct Node {
    int data; // The data stored in the node
    struct Node* prev; // Pointer to the previous node in the list
    struct Node* next; // Pointer to the next node in the list
};

// Function to create a new node
Node* newNode(int data) {
    Node* temp = new Node; // Allocate memory for a new node
    temp->data = data; // Set the data of the new node
    temp->prev = NULL; // Set the previous pointer of the new node to NULL
    temp->next = NULL; // Set the next pointer of the new node to NULL
    return temp; // Return the new node
}

// Driver code
int main() {
    int n, data, key; // Declare variables for the number of nodes, node data, and key for deletion
    Node* head = NULL; // Initialize the head of the list to NULL
    cout << "Enter the number of nodes: ";
    cin >> n; // Get the number of nodes from the user
    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data; // Get the data for each node from the user
        if (head == NULL) {
            head = newNode(data); // If the list is empty, set the head to the new node
        } else {
            Node* temp = head; // Otherwise, traverse the list to the end
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode(data); // Set the next pointer of the last node to the new node
            temp->next->prev = temp; // Set the previous pointer of the new node to the last node
        }
    }
    cout << "Doubly linked list: ";
    Node* temp = head; // Traverse the list and print the data of each node
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Enter the data to delete: ";
    cin >> key; // Get the key for deletion from the user
    temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next; // Traverse the list to find the node with the key for deletion
    if (temp == NULL)
        return 0; // If the key is not found, exit the program
    if (temp->prev != NULL)
        temp->prev->next = temp->next; // Update the previous and next pointers of the nodes surrounding the deleted node
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (head == temp)
        head = temp->next; // Update the head of the list if the deleted node was the head
    delete(temp); // Deallocate memory for the deleted node
    cout << "Doubly linked list after deletion: ";
    temp = head; // Traverse the list after deletion and print the data of each node
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}