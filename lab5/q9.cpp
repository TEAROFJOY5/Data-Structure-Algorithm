#include <iostream>
#include <string>
using namespace std;

#define N 5

string arr[N];
int front = -1;
int rear = -1;

bool isEmpty()
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if ((rear + 1) % N == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(string person)
{
    if (isFull())
    {
        cout << "Queue is full. " << person << " cannot enter." << endl;
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % N;
        }

        arr[rear] = person;

        cout << person << " entered the waiting queue." << endl;
    }
}

string dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nobody to remove." << endl;
        return "";
    }
    else
    {
        string person = arr[front];

        cout << person << " has been served and removed." << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % N;
        }

        return person;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Waiting Queue: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % N;
        }

        cout << endl;
        cout << "Front: " << arr[front] << endl;
        cout << "Rear: " << arr[rear] << endl;
    }

    if (isFull())
    {
        cout << "Queue Status: Full" << endl;
    }
    else
    {
        cout << "Queue Status: Not Full" << endl;
    }

    cout << endl;
}

int main()
{
    cout << "Inserting people into the waiting queue" << endl;

    enqueue("Ali");
    display();

    enqueue("Rustam");
    display();

    enqueue("Mehdi");
    display();

    enqueue(" ");
    display();

    enqueue("Hassan");
    display();

    cout << "Now the queue is full." << endl << endl;

    enqueue("Usman");
    display();

    cout << "Removing people from the front" << endl;

    dequeue();
    display();

    dequeue();
    display();

    cout << "Inserting new people into available positions" << endl;

    enqueue("Afnan");
    display();

    enqueue("Saif");
    display();

    return 0;
}
