#include <iostream>
using namespace std;
// Creating Doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};

Node* creatDoublyLL(Node* head) {
    bool choice = true;

    while (choice) {
        Node *temp, *currNode, *prevNode, *newNode;

        newNode = new Node();
        cout << "Enter the data: ";
        cin >> newNode->data;

        newNode->next = nullptr;
        newNode->prev = nullptr;

        // First node
        if (head == nullptr) {
            head = newNode;
        }
        else {
            temp = head;

            // Go to last node
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            currNode = temp;
            currNode->next = newNode;
            newNode->prev = currNode;
        }

        cout << "Enter 1 to continue or 0 to stop: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter 0 or 1 only.\n";
            choice = true;
        }
    }

    return head;
}

int main()
{
    Node* head = nullptr;
    head = creatDoublyLL(head);
    
    return 0;
}
