#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node( int d);
    
};
Node* temp=NULL;
    Node( int d)
    {
        data = d;
        next = temp;
        temp = next;
        
    }
class Queue{
    public:
        
        Node* front;
        Node* rear;
    Queue( ) {
        front = NULL;
        rear = NULL:
    }
 void enque( int d)
  {
    
    if( rear == NULL )
    {
        rear = newNode;
        rear->next = NULL;
     }
  }
};

int main()
{
    
    return 0;
}
