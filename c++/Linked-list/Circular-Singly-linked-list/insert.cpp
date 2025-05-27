#include <iostream>

using namespace std;

// Define a struct to represent a node in the circular linked list
struct Node {
    int data; // data stored in the node
    struct Node* next; // pointer to the next node in the list
};

int main() {
    // Initialize the head of the list to NULL
    struct Node* head = NULL;

    // Take user input for the number of nodes
    int n, data, index;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Insert nodes at the beginning of the list
    for (int i = 0; i < n; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        // Create a new node with the user-input data
        struct Node* temp = new Node;
        temp->data = data;

        // If the list is empty, set the head to the new node
        if (head == NULL) {
            head = temp;
            head->next = head; // circular link
        } else {
            // Insert the new node at the beginning of the list
            temp->next = head->next;
            head->next = temp;
            head = temp;
        }
    }

    // Take user input for the position of insertion
    cout << "Enter the position for insertion: ";
    cin >> index;

    // Calculate the length of the list
    struct Node* temp = head;
    int len = 1;
    while (temp->next!= head) {
        temp = temp->next;
        len++;
    }

    // Check if the insertion position is valid
    if (index > len || index < 0) {
        cout << "Wrong data given, insertion not possible!" << endl;
        return 0;
    }

    // Insert a new node at the specified position
    if (index == 0) {
        cout << "Enter data for new node: ";
        cin >> data;

        // Create a new node with the user-input data
        temp = new Node;
        temp->data = data;

        // Insert the new node at the beginning of the list
        temp->next = head->next;
        head->next = temp;
        head = temp;
    } else {
        // Find the node at the specified position
        struct Node* prev = head;
        struct Node* next = head->next;
        int count = 1;
        while (len > 0) {
            if (index == count) {
                cout << "Enter data for new node: ";
                cin >> data;

                // Create a new node with the user-input data
                temp = new Node;
                temp->data = data;

                // Insert the new node at the specified position
                temp->next = next;
                prev->next = temp;
                break;
            }
            prev = prev->next;
            next = prev->next;
            len--;
            count++;
        }
    }

    // Display the list
    temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp!= head);
    cout << endl;

    return 0;
}