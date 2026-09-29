#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define N 5

// STACK 

string stackArr[N];
int stackTop = -1;

void push(string value)
{
    if (stackTop == N - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        stackArr[++stackTop] = value;
        cout << value << " pushed into stack" << endl;
    }
}

string pop()
{
    if (stackTop == -1)
    {
        cout << "Stack is empty" << endl;
        return "";
    }
    else
    {
        string value = stackArr[stackTop--];
        cout << value << " popped from stack" << endl;
        return value;
    }
}

void displayStack()
{
    if (stackTop == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack: ";

        for (int i = stackTop; i >= 0; i--)
        {
            cout << stackArr[i] << " ";
        }

        cout << endl;
    }
}


// LINEAR QUEUE 

string linearQueue[N];
int front = -1;
int rear = -1;

void enqueueLinear(string value)
{
    if (rear == N - 1)
    {
        cout << "Linear queue is full" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        linearQueue[++rear] = value;

        cout << value << " inserted into linear queue" << endl;
    }
}

string dequeueLinear()
{
    if (front == -1 || front > rear)
    {
        cout << "Linear queue is empty" << endl;
        return "";
    }
    else
    {
        string value = linearQueue[front++];

        cout << value << " removed from linear queue" << endl;

        return value;
    }
}

void displayLinearQueue()
{
    if (front == -1 || front > rear)
    {
        cout << "Linear queue is empty" << endl;
    }
    else
    {
        cout << "Linear Queue: ";

        for (int i = front; i <= rear; i++)
        {
            cout << linearQueue[i] << " ";
        }

        cout << endl;
        cout << "Front: " << linearQueue[front] << endl;
        cout << "Rear: " << linearQueue[rear] << endl;
    }
}


// CIRCULAR QUEUE
string circularQueue[N];
int circularFront = -1;
int circularRear = -1;

bool isEmpty()
{
    if (circularFront == -1)
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
    if ((circularRear + 1) % N == circularFront)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueueCircular(string value)
{
    if (isFull())
    {
        cout << "Circular queue is full" << endl;
    }
    else
    {
        if (isEmpty())
        {
            circularFront = 0;
            circularRear = 0;
        }
        else
        {
            circularRear = (circularRear + 1) % N;
        }

        circularQueue[circularRear] = value;

        cout << value << " inserted into circular queue" << endl;
    }
}

string dequeueCircular()
{
    if (isEmpty())
    {
        cout << "Circular queue is empty" << endl;
        return "";
    }
    else
    {
        string value = circularQueue[circularFront];

        if (circularFront == circularRear)
        {
            circularFront = -1;
            circularRear = -1;
        }
        else
        {
            circularFront = (circularFront + 1) % N;
        }

        cout << value << " removed from circular queue" << endl;

        return value;
    }
}

void displayCircularQueue()
{
    if (isEmpty())
    {
        cout << "Circular queue is empty" << endl;
    }
    else
    {
        cout << "Circular Queue: ";

        int i = circularFront;

        while (true)
        {
            cout << circularQueue[i] << " ";

            if (i == circularRear)
            {
                break;
            }

            i = (i + 1) % N;
        }

        cout << endl;
        cout << "Front: " << circularQueue[circularFront] << endl;
        cout << "Rear: " << circularQueue[circularRear] << endl;
    }
}


// EXPRESSION CONVERSION

char operatorStack[N * 10];
int operatorTop = -1;

void pushOperator(char value)
{
    if (operatorTop < N * 10 - 1)
    {
        operatorStack[++operatorTop] = value;
    }
}

char popOperator()
{
    if (operatorTop == -1)
    {
        return '\0';
    }
    else
    {
        return operatorStack[operatorTop--];
    }
}

char peekOperator()
{
    if (operatorTop == -1)
    {
        return '\0';
    }
    else
    {
        return operatorStack[operatorTop];
    }
}

int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string infixToPostfix(string infix)
{
    string postfix = "";

    operatorTop = -1;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            pushOperator(ch);
        }
        else if (ch == ')')
        {
            while (operatorTop != -1 && peekOperator() != '(')
            {
                postfix += popOperator();
            }

            if (operatorTop != -1)
            {
                popOperator();
            }
        }
        else if (isOperator(ch))
        {
            while (operatorTop != -1 &&
                   peekOperator() != '(' &&
                  (precedence(peekOperator()) > precedence(ch) ||
                  (precedence(peekOperator()) == precedence(ch)
                   && ch != '^')))
            {
                postfix += popOperator();
            }

            pushOperator(ch);
        }
    }

    while (operatorTop != -1)
    {
        postfix += popOperator();
    }

    return postfix;
}

string infixToPrefix(string infix)
{
    string reversed = "";
    string postfix = "";
    string prefix = "";

    for (int i = infix.length() - 1; i >= 0; i--)
    {
        if (infix[i] == '(')
        {
            reversed += ')';
        }
        else if (infix[i] == ')')
        {
            reversed += '(';
        }
        else
        {
            reversed += infix[i];
        }
    }

    operatorTop = -1;

    for (int i = 0; i < reversed.length(); i++)
    {
        char ch = reversed[i];

        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            pushOperator(ch);
        }
        else if (ch == ')')
        {
            while (operatorTop != -1 && peekOperator() != '(')
            {
                postfix += popOperator();
            }

            if (operatorTop != -1)
            {
                popOperator();
            }
        }
        else if (isOperator(ch))
        {
            while (operatorTop != -1 &&
                   peekOperator() != '(' &&
                  (precedence(peekOperator()) > precedence(ch) ||
                  (precedence(peekOperator()) == precedence(ch)
                   && ch == '^')))
            {
                postfix += popOperator();
            }

            pushOperator(ch);
        }
    }

    while (operatorTop != -1)
    {
        postfix += popOperator();
    }

    for (int i = postfix.length() - 1; i >= 0; i--)
    {
        prefix += postfix[i];
    }

    return prefix;
}



int main()
{
    int choice;
    string value;
    string expression;

    do
    {
        cout << "\n========== LAB 05 MENU ==========" << endl;
        cout << "1. Push into Stack" << endl;
        cout << "2. Pop from Stack" << endl;
        cout << "3. Display Stack" << endl;
        cout << "4. Enqueue in Linear Queue" << endl;
        cout << "5. Dequeue from Linear Queue" << endl;
        cout << "6. Display Linear Queue" << endl;
        cout << "7. Enqueue in Circular Queue" << endl;
        cout << "8. Dequeue from Circular Queue" << endl;
        cout << "9. Check Circular Queue isFull" << endl;
        cout << "10. Check Circular Queue isEmpty" << endl;
        cout << "11. Display Circular Queue" << endl;
        cout << "12. Infix to Postfix" << endl;
        cout << "13. Infix to Prefix" << endl;
        cout << "14. Convert Infix to Both" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;

        switch (choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                displayStack();
                break;

            case 2:
                pop();
                displayStack();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueueLinear(value);
                displayLinearQueue();
                break;

            case 5:
                dequeueLinear();
                displayLinearQueue();
                break;

            case 6:
                displayLinearQueue();
                break;

            case 7:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueueCircular(value);
                displayCircularQueue();
                break;

            case 8:
                dequeueCircular();
                displayCircularQueue();
                break;

            case 9:
                if (isFull())
                {
                    cout << "Circular queue is FULL" << endl;
                }
                else
                {
                    cout << "Circular queue is NOT FULL" << endl;
                }
                break;

            case 10:
                if (isEmpty())
                {
                    cout << "Circular queue is EMPTY" << endl;
                }
                else
                {
                    cout << "Circular queue is NOT EMPTY" << endl;
                }
                break;

            case 11:
                displayCircularQueue();
                break;

            case 12:
                cout << "Enter infix expression: ";
                cin >> expression;

                cout << "Infix: " << expression << endl;
                cout << "Postfix: "
                     << infixToPostfix(expression) << endl;
                break;

            case 13:
                cout << "Enter infix expression: ";
                cin >> expression;

                cout << "Infix: " << expression << endl;
                cout << "Prefix: "
                     << infixToPrefix(expression) << endl;
                break;

            case 14:
                cout << "Enter infix expression: ";
                cin >> expression;

                cout << "Infix: " << expression << endl;
                cout << "Postfix: "
                     << infixToPostfix(expression) << endl;
                cout << "Prefix: "
                     << infixToPrefix(expression) << endl;
                break;

            case 0:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while (choice != 0);

    return 0;
}
