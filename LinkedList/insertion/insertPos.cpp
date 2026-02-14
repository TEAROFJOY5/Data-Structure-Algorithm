#include<iostream>
using namespace std;
// #include<stdin.h>
struct node
    {
        int data;
        struct node *next;
    };

node* CreatLL(){ //This will create Singly Linked List
    
    struct node *head, *newNode, *temp;
    head = 0;
    int choice = 1;
    while(choice)
    {
        // newNode = 
        newNode = new struct node;
        cout<<"Enter data: "<<endl;
        cin>>newNode->data;
        newNode->next = nullptr;
        if (head == 0)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode; // link to previous node
            temp = newNode; // move temp to newNode.

        }
       while (true)
    {
        cout << "Enter 1 to continue or 0 to stop: ";
        cin >> choice;

        if (cin.fail())   // user entered letters like abc
        {
            cin.clear();  
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter 0 or 1 only.\n";
        }
        else if (choice == 0 || choice == 1)
        {
            break;   // valid input
        }
        else
        {
            cout << "Invalid input! Please enter only 0 or 1.\n";
        }
    }
 }
 
 return head;
}

void displayLL(struct node* head) //To display Singly Linked List.
{
   struct node* temp;
   temp = head;
   while(temp != 0)
   {
        cout<<temp->data;
        cout<<" ";
        temp = temp->next;
   }
cout<<endl;
}
node* insertPos(struct node *head, int count){
     struct node* newNode;
     int pos, i = 1;
     newNode = new struct node;
     cout<<"Enter the position in which you want to enter:"<<endl;
     cin>>pos;
     if(pos>count)
     {
        cout<<"Invalid position:";
        return head; 
     }
     cout<<"Enter data you want to add: "<<endl;
     cin>>newNode->data;
     newNode->next = 0;
     struct node* temp;
     temp = head;
      while(i<pos)
      {
        temp = temp->next;
        i++;
      }
      newNode->next = temp->next; 
      temp->next = newNode;
     return head;
}
int main()
{
   node* head = CreatLL(); //Create only 3 elements list.
   head = insertPos(head,3);
   displayLL(head);
    return 0;
}
