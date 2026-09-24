#include <iostream>
#include <string>
using namespace std;

struct Node {
    char task;
    Node* link;
};

Node* top = NULL;

void push(char t)
{
    Node* newNode = new Node;

    newNode->task = t;
    newNode->link = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
    {
        return '\0';
    }
    else
    {
        char del = top->task;

        Node* temp = top;
        top = top->link;
        delete temp;

        return del;
    }
}

char peek()
{
    if (top == NULL)
    {
        return '\0';
    }

    return top->task;
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(string expression)
{
    string postfix = "";

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == ' ')
        {
            continue;
        }

        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != NULL && peek() != '(')
            {
                postfix += pop();
            }

            if (top != NULL && peek() == '(')
            {
                pop();
            }
        }
        else if (isOperator(ch))
        {
            while (top != NULL &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix += pop();
            }

            push(ch);
        }
    }

    while (top != NULL)
    {
        postfix += pop();
    }

    return postfix;
}

int main()
{
    string expression;

    cout << "Enter infix expression: ";
    cin >> expression;

    cout << "Postfix expression: "
         << infixToPostfix(expression) << endl;
}
