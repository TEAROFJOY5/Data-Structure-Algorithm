#include <iostream>
#include <string>
using namespace std;
class Student
{ 
  public:
     string name;
     string course;
Student(string n, string c)
{
    name = n;
    course = c;
}

};
class Node
{
 public:
    Student data;
    Node* next;
Node(Student s) : data(s)
{
    next = NULL;
}
};
// ==================== QUEUE ====================
class Queue
{
 private:
    Node* front;
    Node* rear;
public:
Queue()
{
    front = NULL;
    rear = NULL;
}
void enqueue(Student s)
{
Node* newNode = new Node(s);
if (rear == NULL)
{
    front = rear = newNode;
}
else
{
    rear->next = newNode;
    rear = newNode;
}
}
Student dequeue()
{
if (front == NULL)
{
    cout << "Queue is empty!" << endl;
    return Student("", "");
}



    Node* temp = front;
    Student s = temp->data;
    front = front->next;
if (front == NULL)
{
    rear = NULL;
}
    delete temp;
    return s;
}
bool isEmpty()
{
    return front == NULL;
}
};
// ==================== STACK ====================
class Stack
{
 private:
    Node* top;
 public:
    Stack()
 {
     top = NULL;
 }
void push(Student s)
{
    Node* newNode = new Node(s);
    newNode->next = top;
    top = newNode;
}
Student pop()
{
    if (top == NULL)
 {
     cout << "Stack is empty!" << endl;
     return Student("", "");
 }
    Node* temp = top;
    Student s = temp->data;


    top = top->next;
    delete temp;
    return s;
}
 bool isEmpty()
 {
     return top == NULL;
 }
void display()
 {
    Node* temp = top;
    while (temp != NULL)
      {
         cout << temp->data.name
        << " (" << temp->data.course << ")" << endl;
         temp = temp->next;
       }
 }
};
// ==================== MAIN ====================
int main()
{
  Queue students;
  Stack dsStack;
  Stack coalStack;
  Stack dataScienceStack;
// Students in random initial order
students.enqueue(Student("Ali", "DS"));
students.enqueue(Student("Ahmed", "Data Science"));
students.enqueue(Student("Hassan", "COAL"));
students.enqueue(Student("Usman", "DS"));
students.enqueue(Student("Bilal", "COAL"));
students.enqueue(Student("Hamza", "Data Science"));
// Process queue using FIFO
while (!students.isEmpty())
  {
       Student current = students.dequeue();
       if (current.course == "DS")
      {
            dsStack.push(current);
        }
       else if (current.course == "COAL")
       {
         coalStack.push(current);
       }
       else if (current.course == "Data Science")
       {
          dataScienceStack.push(current);
        }
   }
// Display all stacks from TOP to BOTTOM
  cout << "\nDS Stack (Top to Bottom):" << endl;
  dsStack.display();
  cout << "\nCOAL Stack (Top to Bottom):" << endl;
  coalStack.display();
  cout << "\nData Science Stack (Top to Bottom):" << endl;
  dataScienceStack.display();
 return 0;
}
