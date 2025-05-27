#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int main() {
    Node* head = NULL;
    int numNodes, data, updateData;

    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        if (head == NULL) {
            head = new Node();
            head->data = data;
            head->next = head;
            head->prev = head;
        } else {
            Node* temp = new Node();
            temp->data = data;
            Node* a = head;
            while (a->next != head) {
                a = a->next;
            }
            a->next = temp;
            temp->prev = a;
            temp->next = head;
            head->prev = temp;
        }
    }

    cout << "Enter the data to update: ";
    cin >> updateData;

    Node* temp = head;
    while (temp->next != head) {
        if (temp->data == updateData) {
            cout << "Enter the new data: ";
            int newData;
            cin >> newData;
            temp->data = newData;
            break;
        }
        temp = temp->next;
    }
    if (temp->data == updateData) {
        cout << "Enter the new data: ";
        int newData;
        cin >> newData;
        temp->data = newData;
    } else {
        cout << "Data not found in the list" << endl;
    }

    cout << "Updated list: ";
    temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;

    return 0;
}








// - USING POSITION -  



// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node* prev;
// };

// int main() {
//     Node* head = NULL;
//     int numNodes, data, pos, newData;

//     cout << "Enter the number of nodes: ";
//     cin >> numNodes;

//     for (int i = 0; i < numNodes; i++) {
//         cout << "Enter data for node " << i + 1 << ": ";
//         cin >> data;
//         if (head == NULL) {
//             head = new Node();
//             head->data = data;
//             head->next = head;
//             head->prev = head;
//         } else {
//             Node* temp = new Node();
//             temp->data = data;
//             Node* a = head;
//             while (a->next != head) {
//                 a = a->next;
//             }
//             a->next = temp;
//             temp->prev = a;
//             temp->next = head;
//             head->prev = temp;
//         }
//     }

//     cout << "Enter the position to update: ";
//     cin >> pos;

//     cout << "Enter the new data: ";
//     cin >> newData;

//     Node* temp = head;
//     int count = 1;
//     while (temp->next != head) {
//         if (count == pos) {
//             temp->data = newData;
//             break;
//         }
//         temp = temp->next;
//         count++;
//     }
//     if (count == pos) {
//         temp->data = newData;
//     } else {
//         cout << "Position out of range" << endl;
//     }

//     cout << "Updated list: ";
//     temp = head;
//     do {
//         cout << temp->data << " ";
//         temp = temp->next;
//     } while (temp != head);
//     cout << endl;

//     return 0;
// }