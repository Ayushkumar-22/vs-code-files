#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    cout << "Linked list: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    int position;
    cout << "Enter the position to delete: ";
    cin >> position;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return 0;
    }

    temp = head;
    if (position == 1) {
        head = temp->next;
        delete temp;
    } else {
        for (int i = 1; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of range" << endl;
            return 0;
        }

        Node* next = temp->next->next;
        delete temp->next;
        temp->next = next;
    }

    cout << "Linked list after deletion: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}