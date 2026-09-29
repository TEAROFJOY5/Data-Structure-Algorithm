#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string history;
    Node* next;
};

Node* top = NULL;

void push(string web)
{
    Node* newNode = new Node;

    newNode->history = web;
    newNode->next = top;
    top = newNode;
}

string pop()
{
    if (top == NULL)
    {
        cout << "History is empty. Nothing to go back" << endl;
        return "";
    }
    else
    {
        Node* temp = top;
        string web = top->history;
        top = top->next;
        delete temp;
        return web;
    }
}

void display()
{
    Node* temp = top;

    if (top == NULL)
    {
        cout << "History is empty" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << " " << temp->history << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    push("Google");
    display();

    push("YouTube");
    display();

    push("Facebook");
    display();

    push("Wikipedia");
    display();

    cout << "Now going Back\n";

    pop();
    display();

    pop();
    display();

    pop();
    display();

    pop();
    display();

    return 0;
}
