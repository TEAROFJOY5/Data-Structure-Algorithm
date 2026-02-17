#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Insert at beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = new Node(data);

    // If list is empty
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;

    return head;
}

// Insert at end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);

    // If list is empty
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Insert at any position (1-based index)
Node* insertAtPosition(Node* head, int data, int position) {

    // Insert at beginning
    if (position == 1) {
        return insertAtBeginning(head, data);
    }

    if (head == NULL) {
        cout << "List is empty\n";
        return head;
    }

    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 1;

    // Traverse to (position - 1)
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != position - 1) {
        cout << "Invalid position\n";
        delete newNode;
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Print circular singly linked list
void printList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Main function
int main() {
    Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    head = insertAtBeginning(head, 5);
    head = insertAtPosition(head, 25, 4);

    cout << "Circular Singly Linked List: ";
    printList(head);

    return 0;
}
