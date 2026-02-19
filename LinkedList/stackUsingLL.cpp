#include <iostream>
using namespace std;
// Creating stack using linked list
class Node {
public:
    int data;
    Node* next;


    Node() {
        data = 0;
        next = nullptr;
  
    }
};
Node* top = nullptr;
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
void pop() {
    if (top == nullptr) {
        cout << "Stack underflow" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}
void display() {
    if (top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = top;
    cout << "Stack elements: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void peek(){
    if(top == nullptr){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"top elementt: "<<top->data<<endl;
}
int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    cout<<"after pop"<<endl;
    peek();
    
    display();
    return 0;
}
