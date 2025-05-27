#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL; // Initialize head pointer to NULL

int main() {
    int numNodes, data, position, i;
    Node *newNode, *temp;

    // Ask user for number of nodes
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    // Create nodes one by one and insert at the end
    cout << "Enter the data for each node: ";
    for(i=0; i<numNodes; i++) {
        cin >> data;
        if(i == 0) {
            head = new Node(); // Create first node and make it head
            head->data = data;
            head->next = NULL;
            head->prev = NULL;
            temp = head; // Store address of head node in temp variable
        } else {
            newNode = new Node(); // Create new node
            newNode->data = data;
            newNode->next = NULL;
            newNode->prev = temp; // Link new node with previous node
            temp->next = newNode; // Link previous node with new node
            temp = newNode; // Move temp to new node
        }
    }

    // Ask user for position and data to insert
    int insertData;
    cout << "Enter the position at which to insert new data: ";
    cin >> position;

    cout << "Enter the data to insert: ";
    cin >> insertData;

    // Insert new node at specified position
    if(position == 0) {
        newNode = new Node(); // Create new node
        newNode->data = insertData;
        newNode->next = head; // Link new node with head node
        newNode->prev = NULL;
        head->prev = newNode; // Link head node with new node
        head = newNode; // Make new node as head node
    } else {
        temp = head; // Start from head node
        for(i=0; i<position-1; i++) {
            if(temp == NULL) {
                cout << "Invalid position" << endl;
                return 0;
            }
            temp = temp->next; // Move temp to next node
        }

        if(temp == NULL) {
            cout << "Invalid position" << endl;
            return 0;
        }

        newNode = new Node(); // Create new node
        newNode->data = insertData;
        newNode->next = temp->next; // Link new node with next node
        if(temp->next != NULL)
            temp->next->prev = newNode; // Link next node with new node
        newNode->prev = temp; // Link new node with previous node
        temp->next = newNode; // Link previous node with new node
    }

    // Display the resulting doubly linked list
    cout << "The doubly linked list is: ";
    temp = head;
    while(temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}