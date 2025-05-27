# include <iostream>
using namespace std;
#define max_size 1000

bool push (int stack[], int &top, int value);
bool pop (int stack[], int &top);
int peek (int stack[],int top);
bool isEmpty(int top);
void display (int stack[], int top);

int main(){
    int stack[max_size];   
    int top =-1;   //index of top element (empty stack)
    cout<<"check satck is empty or not"<<endl;
    cout<< isEmpty(top)<<endl;
    cout <<"\ninsert an elemnt into the satck"<<endl;
    push (stack , top, 4);
    push (stack , top, 2);
    push (stack , top, 8);
    push (stack , top, 10);
    display (stack, top);
    cout<<"\n remove an element from the stack"<<endl;
    cout << pop (stack, top)<<endl;
    display (stack, top);
    cout<<"peek top element of the stack"<<endl;
    cout<<peek(stack, top)<<endl;

    return 0;
}


bool push(int stack[], int &top, int value){
    if(top>=max_size-1){
        cout<<"stack is full"<<endl;
        return false;
    }
    stack[++top] = value;
    return true;
}


bool pop(int stack[], int &top){
    if(top<0){
        cout<<"stack is under-flow"<<endl;
        return false;
    }
    return stack[top--];
}


int peek(int stack[], int top){
    if(top<0){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return stack[top];
}


bool isEmpty(int top){
    return (top<0);
}


void display(int stack[], int top){
    if (top<0){
        cout<<"stack is empty"<<endl;
    }
    cout<<"stack element";
    for(int i = top; i>=0; i--){
        cout<< stack[i]<<" ";
    }
    cout<<endl;
}