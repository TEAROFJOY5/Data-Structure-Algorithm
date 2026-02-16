#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* circularSingly(Node* head, int data) {
    Node* newNode = new Node(data);

    // If list is empty
    if (head == NULL) {
        newNode->next = newNode; // circular link
        return newNode;
    }

    Node* temp = head;

    // Traverse till last node
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Function to print circular linked list
void printList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = NULL;

    head = circularSingly(head, 200);
    head = circularSingly(head, 300);
    head = circularSingly(head, 400);

    printList(head);

    return 0;
}
