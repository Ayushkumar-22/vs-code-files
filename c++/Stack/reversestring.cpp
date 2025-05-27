#include <iostream>
using namespace std;

#define MAX_SIZE 1000


void push(char stack[], int &top, char value);
char pop(char stack[], int &top);
bool isEmpty(int top);
bool isFull(int top);
void reverseString(char str[], int length);

int main() {
    char str[] = "Hello, World!";
    int length = 0;

    // Calculate the length of the string    --  for (length = 0; str[length] != '\0'; length++);
    while (str[length] != '\0') {
        length++;
    }

    reverseString(str, length);
    
    cout << "Reversed string: " << str << endl;

    return 0;
}




void push(char stack[], int &top, char value) {
    if (isFull(top)) {
        cout << "Stack is full" << endl;
        return;
    }
    stack[++top] = value;
}


char pop(char stack[], int &top) {
    if (isEmpty(top)) {
        cout << "Stack is empty" << endl;
        return '\0';
    }
    return stack[top--];
}


bool isEmpty(int top) {
    return (top < 0);
}


bool isFull(int top) {
    return (top >= MAX_SIZE - 1);
}


void reverseString(char str[], int length) {
    char stack[MAX_SIZE];
    int top = -1; // Initialize top index to -1 (empty stack)

    // Push each character of the string onto the stack
    for (int i = 0; i < length; i++) {
        push(stack, top, str[i]);
    }

    // Pop characters from the stack and place them back into the string
    for (int i = 0; i < length; i++) {
        str[i] = pop(stack, top);
    }
}