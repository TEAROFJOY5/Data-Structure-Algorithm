#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }
};

// Delete at beginning
Node* delatBeg(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return head;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
    return head;
}

// Delete at end
Node* delatEnd(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return head;
    }

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
    return head;
}

// Delete at given position (1-based index)
Node* delatPos(Node* head, int pos) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return head;
    }

    if (pos == 1) {
        return delatBeg(head);
    }

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range" << endl;
        return head;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    return head;
}

// Display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node();
    head->data = 1;

    head->next = new Node();
    head->next->data = 2;
    head->next->prev = head;

    head->next->next = new Node();
    head->next->next->data = 3;
    head->next->next->prev = head->next;

    cout << "Original list: ";
    display(head);

    head = delatBeg(head);
    cout << "After deleting at beginning: ";
    display(head);

    head = delatEnd(head);
    cout << "After deleting at end: ";
    display(head);

    head = delatPos(head, 1);
    cout << "After deleting at position 1: ";
    display(head);

    return 0;
}
