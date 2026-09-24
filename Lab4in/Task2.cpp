#include <iostream>
#include <string>
using namespace std;

struct Node {
    string task;
    Node* link;
};

Node* top = NULL;

void push(string t)
{
    Node* newNode = new Node;

    newNode->task = t;
    newNode->link = top;
    top = newNode;

    cout << "You have entered " << newNode->task << endl;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        string del = top->task;

        Node* temp = top;   
        top = top->link;    
        delete temp;      

        cout << del << " popped" << endl;
    }
}

int main()
{
    push("swimming");
    push("nap");
    push("eating");

    pop();
}
