#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int numNodes;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            head->next = tail;
            tail->prev = head;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
    }

    int deleteData;
    cout << "Enter the data to delete: ";
    cin >> deleteData;

    Node* temp = head;
    Node* prevNode = NULL;
    while (temp->data != deleteData && temp->next != head) {
        prevNode = temp;
        temp = temp->next;
    }

    if (temp->data != deleteData) {
        cout << "Data not found." << endl;
        return 0;
    }

    if (prevNode == NULL) {
        head = head->next;
        tail->next = head;
        head->prev = tail;
    } else if (temp->next == head) {
        tail = prevNode;
        tail->next = head;
        head->prev = tail;
    } else {
        prevNode->next = temp->next;
        temp->next->prev = prevNode;
    }

    delete temp;

    cout << "List after deletion: ";
    temp = head;
    while (temp->next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;

    return 0;
}






// - USING POSITION - 





// #include <iostream>

// using namespace std;

// int main() {
//     struct Node {
//         int data;
//         Node* next;
//         Node* prev;
//     };

//     Node* head = NULL;
//     Node* tail = NULL;

//     int numNodes, data, pos;

//     cout << "Enter the number of nodes: ";
//     cin >> numNodes;

//     for (int i = 0; i < numNodes; i++) {
//         cout << "Enter data for node " << i + 1 << ": ";
//         cin >> data;

//         Node* newNode = new Node();
//         newNode->data = data;
//         newNode->next = NULL;
//         newNode->prev = NULL;

//         if (head == NULL) {
//             head = newNode;
//             tail = newNode;
//             head->next = tail;
//             tail->prev = head;
//         } else {
//             newNode->prev = tail;
//             tail->next = newNode;
//             tail = newNode;
//             tail->next = head;
//             head->prev = tail;
//         }
//     }

//     cout << "Enter the position of the node to be deleted: ";
//     cin >> pos;

//     Node* temp = head;
//     Node* prevNode = NULL;
//     int count = 1;

//     while (count < pos && temp->next!= head) {
//         prevNode = temp;
//         temp = temp->next;
//         count++;
//     }

//     if (count!= pos) {
//         cout << "Position out of range." << endl;
//         return 0;
//     }

//     if (prevNode == NULL) {
//         head = head->next;
//         tail->next = head;
//         head->prev = tail;
//     } else if (temp->next == head) {
//         tail = prevNode;
//         tail->next = head;
//         head->prev = tail;
//     } else {
//         prevNode->next = temp->next;
//         temp->next->prev = prevNode;
//     }

//     delete temp;

//     cout << "List after deletion: ";
//     temp = head;
//     while (temp->next!= head) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << temp->data << endl;

//     return 0;
// }