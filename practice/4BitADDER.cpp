#include <iostream>
using namespace std;
class Node
{
public:
int digit;
Node* next;
Node(int d)
{
digit = d;
next = NULL;
}
};
// Insert a digit at the end of the list
void insertEnd(Node*& head, int digit)
{
Node* newNode = new Node(digit);
if (head == NULL)
{
head = newNode;



return;
}
Node* temp = head;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = newNode;
}
// Display the linked list
void display(Node* head)
{
Node* temp = head;
while (temp != NULL)
{
cout << temp->digit;
if (temp->next != NULL)
cout << " -> ";
temp = temp->next;
}
cout << " -> NULL" << endl;
}
// Add corresponding digits of two lists
void addLists(Node* L1, Node* L2, Node*& L3)
{
int carry = 0;
while (L1 != NULL && L2 != NULL)
{
int sum = L1->digit + L2->digit + carry;
int digit = sum % 10;
carry = sum / 10;
insertEnd(L3, digit);
L1 = L1->next;
L2 = L2->next;
}
if (carry > 0)
{
insertEnd(L3, carry);

}
}
int main()
{
Node* L1 = NULL;
Node* L2 = NULL;
Node* L3 = NULL;
// L1 = 1956
insertEnd(L1, 1);
insertEnd(L1, 9);
insertEnd(L1, 5);
insertEnd(L1, 6);
// L2 = 1239
insertEnd(L2, 1);
insertEnd(L2, 2);
insertEnd(L2, 3);
insertEnd(L2, 9);
cout << "L1: ";
display(L1);
cout << "L2: ";
display(L2);
addLists(L1, L2, L3);
cout << "L3: ";
display(L3);
return 0;
}
