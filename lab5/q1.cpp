#include <iostream>
#include <string>
using namespace std;
#define N 5
 string arr[N];
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
void display()
{
    for(int i = top; i>=0; i--)
        {
            cout<<" "<<arr[i]<<" ";
        }
      cout<<endl;  
}
int main()
{

    push("Study", arr);
    display();
    push("Exercise", arr);
    display();
    push("Homework", arr);
    display();
    cout<<"Now popping\n";
     pop(arr);
    display();
     pop(arr);
    display();
     pop(arr);
    display();
   pop(arr);
    display();
    return 0;
}
