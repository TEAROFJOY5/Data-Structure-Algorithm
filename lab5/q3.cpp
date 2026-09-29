#include <iostream>
#include <string>
using namespace std;

#define N 5

string arr[N];
int front = -1;
int rear = -1;

void enqueue(string student)
{
    if (rear == N - 1)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        arr[++rear] = student;
    }
}

string dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty. Nothing to dequeue" << endl;
        return "";
    }
    else
    {
        return arr[front++];
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue: ";

        for (int i = front; i <= rear; i++)
        {
            cout << " " << arr[i] << " ";
        }

        cout << endl;

        cout << "Front: " << arr[front] << endl;
        cout << "Rear: " << arr[rear] << endl;
    }
}

int main()
{
    enqueue("Ali");
    display();

    enqueue("Ahmed");
    display();

    enqueue("Turab");
    display();

    enqueue("Sikandar");
    display();

    cout << "Now dequeuing\n";

    dequeue();
    display();

    dequeue();
    display();

    enqueue("Hassan");
    display();

    dequeue();
    display();

    return 0;
}
