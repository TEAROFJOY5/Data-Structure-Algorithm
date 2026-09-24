#include <iostream>
#include <string>
#define N 5

using namespace std;

int top = -1;

void push(string task, string arr[])
{
    if (top == N - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        arr[++top] = task;
    }
}

string pop(string arr[])
{
    if (top == -1)
    {
        cout << "Stack is empty. Nothing to pop" << endl;
        return "";
    }
    else
    {
        return arr[top--];
    }
}

int main()
{
    string arr[N];

    push("Study", arr);
    push("Exercise", arr);
    push("Homework", arr);

    cout << pop(arr) << endl;
    cout << pop(arr) << endl;
    cout << pop(arr) << endl;

    return 0;
}

