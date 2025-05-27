#include <iostream>
using namespace std;

#define MAX_SIZE 1000 


void push(char stack[], int &top, char value);
char pop(char stack[], int &top);
bool isEmpty(int top);
bool isFull(int top);
bool areSymbolsBalanced(const char expr[]);

int main() {
    char expr[] = "{[()]}";
    
    if (areSymbolsBalanced(expr)) {
        cout << "The symbols are balanced." << endl;
    } else {
        cout << "The symbols are not balanced." << endl;
    }
    
    return 0;
}




void push(char stack[], int &top, char value) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack is full" << endl;
        return;
    }
    stack[++top] = value;
}



char pop(char stack[], int &top) {
    if (top < 0) {
        cout << "Stack is empty" << endl;
        return '\0'; // Return a null character to indicate an empty stack
    }
    return stack[top--];
}


bool isEmpty(int top) {
    return (top < 0);
}


bool isFull(int top) {
    return (top >= MAX_SIZE - 1);
}


bool areSymbolsBalanced(const char expr[]) {
    char stack[MAX_SIZE];
    int top = -1; // Initialize top index to -1 (empty stack)
    
    // Iterate through each character in the string
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        
        switch (ch) {
            case '(':
            case '[':
            case '{':
                push(stack, top, ch); // Push opening symbols onto the stack
                break;
            case ')':
                if (isEmpty(top) || pop(stack, top) != '(') {
                    return false; // Mismatch or extra closing parenthesis
                }
                break;
            case ']':
                if (isEmpty(top) || pop(stack, top) != '[') {
                    return false; // Mismatch or extra closing bracket
                }
                break;
            case '}':
                if (isEmpty(top) || pop(stack, top) != '{') {
                    return false; // Mismatch or extra closing brace
                }
                break;
        }
    }
    
    // If stack is empty, all symbols are balanced
    return isEmpty(top);
}
