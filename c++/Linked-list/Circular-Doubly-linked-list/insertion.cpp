#include <iostream>

using namespace std;

int main() {
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;
    Node* tail = NULL;

    int numNodes, pos, data;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        Node* newNode = new Node();
        newNode->data = data;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            head->prev = tail;
        }
    }

    cout << "Circular Doubly Linked List: ";
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp!= head);
    cout << endl;

    cout << "Enter the position to insert a new node: ";
    cin >> pos;

    cout << "Enter the data to insert: ";
    cin >> data;

    Node* newNode2 = new Node();
    newNode2->data = data;

    if (head == NULL) {
        head = newNode2;
        tail = newNode2;
        head->next = head;
        head->prev = head;
    } else if (pos == 1) {
        newNode2->next = head;
        newNode2->prev = tail;
        tail->next = newNode2;
        head->prev = newNode2;
        head = newNode2;
    } else {
        Node* temp2 = head;
        int count2 = 1;
        while (count2 < pos - 1) {
            temp2 = temp2->next;
            count2++;
        }

        newNode2->next = temp2->next;
        newNode2->prev = temp2;
        temp2->next->prev = newNode2;
        temp2->next = newNode2;
    }

    cout << "Updated Circular Doubly Linked List: ";
    temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp!= head);
    cout << endl;

    return 0;
}