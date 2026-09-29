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

void enqueue(string value)
{
    if (isFull())
    {
        cout << "Queue is full" << endl;
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

        arr[rear] = value;
    }
}

string dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Nothing to dequeue" << endl;
        return "";
    }
    else
    {
        string value = arr[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % N;
        }

        return value;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue: ";

        int i = front;

        while (true)
        {
            cout << " " << arr[i] << " ";

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
}

int main()
{
    enqueue("Ali");
    display();

    enqueue("Rustam");
    display();

    enqueue("Mehdi");
    display();

    enqueue("");
    display();

    enqueue("Hassan");
    display();

    cout << "Queue is now full" << endl;

    dequeue();
    display();

    dequeue();
    display();

    cout << "Now inserting new students" << endl;

    enqueue("Afnan");
    display();

    enqueue("Saif");
    display();

    return 0;
}
