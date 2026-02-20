#include<iostream>
using namespace std;
// insert a node at beginning, end and at any position of Doubly Linked List
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        data=0;
        next=nullptr;
        prev=nullptr;
    } 
};
Node* createDoublyLinkedList(Node* head){
    Node* temp = nullptr;
    bool choice=true;
    Node* newNode=new Node();
    cout<<"Enter data for new node: ";
    cin>>newNode->data;
    if(head==nullptr){
    head=temp=newNode;
    }
    else{
        temp=head;
        temp->next=newNode;
        newNode->prev=temp;
        temp=newNode;
        cout<<"Do you want to add more nodes? (1 for yes, 0 for no): ";
        cin>>choice;
        while(choice){
            Node* newNode=new Node();
            cout<<"Enter data for new node: ";
            cin>>newNode->data;
            temp->next=newNode;
            newNode->prev=temp;
            temp=newNode;
            cout<<"Do you want to add more nodes? (1 for yes, 0 for no): ";
            cin>>choice; 
        }       

    }
    return head;    
}
Node* insertAtBeg(Node* head){
    Node* temp = nullptr;
    Node* newNode=new Node();
    cout<<"Enter data for new node: ";
    cin>>newNode->data;
    if(head==nullptr){
        head=newNode;
        return head;
    }
    temp=head;
    newNode->next=temp;
    temp->prev=newNode;
    head=newNode;
    
    return head;
}
void display(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* insertAtEnd(Node* head){
    Node* temp = nullptr;
    Node* newNode=new Node();
    cout<<"Enter data for new node: ";
    cin>>newNode->data;
    if(head==nullptr){
        head=newNode;
        return head;
    }
    temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    
    return head;
}
Node* insertAtPos(Node* head){
    Node* temp = nullptr;
    Node* newNode=new Node();
    int pos;
    cout<<"Enter data for new node: ";
    cin>>newNode->data;
    cout<<"Enter position to insert: ";
    cin>>pos;
    if(head==nullptr){
        head=newNode;
        return head;
    }
    temp=head;
    for(int i=1;i<pos-1 && temp!=nullptr;i++){
        temp=temp->next;
    }
    if(temp==nullptr){
        cout<<"Position out of bounds"<<endl;
        return head;
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next!=nullptr){
        temp->next->prev=newNode;
    }
    temp->next=newNode;
    
    return head;
}
int main(){
    Node* head=nullptr;
    int choice;
    do{
        cout<<"1. Create Doubly Linked List"<<endl;
        cout<<"2. Insert at Beginning"<<endl;
        cout<<"3. Insert at End"<<endl;
        cout<<"4. Insert at Position"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                head=createDoublyLinkedList(head);
                break;
            case 2:
                head=insertAtBeg(head);
                break;
            case 3:
                head=insertAtEnd(head);
                break;
            case 4:
                head=insertAtPos(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice!=6);
    return 0;
}
