#include <iostream>

// Define the Node struct with data, next, and prev pointers
struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    // Initialize head and tail pointers to nullptr
    Node* head = nullptr;
    Node* tail = nullptr;

    // Get the number of nodes from the user
    int numNodes;
    std::cout << "Enter the number of nodes: ";
    std::cin >> numNodes;

    // Get the data for each node and create a new node
    std::cout << "Enter the data for each node:\n";
    for (int i = 0; i < numNodes; i++) {
        int data;
        std::cin >> data;

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        // If head is nullptr, set head to newNode
        if (head == nullptr) {
            head = newNode;
        } else {
            // Otherwise, set the next node of the current tail to newNode
            tail->next = newNode;
        }

        // Set tail to newNode
        tail = newNode;
    }

    // Initialize a current pointer to head
    Node* current = head;
    // Print the data of each node in the list
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }

    std::cout << "NULL\n";

    // Get the key and new data from the user
    int key, newData;
    std::cout << "Enter the key to update: ";
    std::cin >> key;
    std::cout << "Enter the new data: ";
    std::cin >> newData;

    // Initialize a current pointer to head
    current = head;
    // Traverse the list until the key is found or the end of the list is reached
    while (current != nullptr) {
        // If the current node's data matches the key, update the data and break out of the loop
        if (current->data == key) {
            current->data = newData;
            break;
        }
        current = current->next;
    }

    // Initialize a current pointer to head
    current = head;
    // Print the data of each node in the list
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }

    std::cout << "NULL\n";

    // Deallocate memory for all nodes in the list
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}


/*

// it take POSITION FOR UPDATE

#include <iostream>

// Define the Node struct with data, next, and prev pointers
struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    // Initialize head and tail pointers to nullptr
    Node* head = nullptr;
    Node* tail = nullptr;

    // Get the number of nodes from the user
    int numNodes;
    std::cout << "Enter the number of nodes: ";
    std::cin >> numNodes;

    // Get the data for each node and create a new node
    std::cout << "Enter the data for each node:\n";
    for (int i = 0; i < numNodes; i++) {
        int data;
        std::cin >> data;

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;

        // If head is nullptr, set head to newNode
        if (head == nullptr) {
            head = newNode;
        } else {
            // Otherwise, set the next node of the current tail to newNode
            tail->next = newNode;
        }

        // Set tail to newNode
        tail = newNode;
    }

    // Initialize a current pointer to head
    Node* current = head;
    // Print the data of each node in the list
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }

    std::cout << "NULL\n";

    // Get the position and new data from the user
    int position, newData;
    std::cout << "Enter the position to update: ";
    std::cin >> position;
    std::cout << "Enter the new data: ";
    std::cin >> newData;

    // Initialize a current pointer to head
    current = head;
    // Traverse the list until the position is found or the end of the list is reached
    int i = 0;
    while (current != nullptr && i < position) {
        current = current->next;
        i++;
    }

    // If the position is found, update the data
    if (current != nullptr) {
        current->data = newData;
    } else {
        // Otherwise, print an error message
        std::cout << "Position not found in the list.\n";
    }

    // Initialize a current pointer to head
    current = head;
    // Print the data of each node in the list
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }

    std::cout << "NULL\n";

    // Deallocate memory for all nodes in the list
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

*/