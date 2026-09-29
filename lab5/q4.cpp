#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define N 100

char arr[N];
int top = -1;

void push(char value)
{
    if (top == N - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        arr[++top] = value;
    }
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        return arr[top--];
    }
}

char peek()
{
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        return arr[top];
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
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
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

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix += pop();
            }

            if (top != -1)
            {
                pop();
            }
        }
        else if (isOperator(ch))
        {
            while (top != -1 && peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) && ch != '^')))
            {
                postfix += pop();
            }

            push(ch);
        }
    }

    while (top != -1)
    {
        postfix += pop();
    }

    return postfix;
}

int main()
{
    string infix = "A-B*(C*D^E)^(F-G*H)+I";

    cout << "Original Infix Expression: " << infix << endl;

    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
