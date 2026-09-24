#include <iostream>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;

    Node(string a, int b) {
        name = a;
        score = b;
        next = NULL;
    }
};

Node* head = NULL;

void insert(string a, int b) {
    Node* newNode = new Node(a, b);

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void sort() {
    if (head == NULL || head->next == NULL)
        return;

    Node* i = head;

    while (i != NULL) {
        Node* j = i->next;

        while (j != NULL) {
            if (i->score < j->score) {
                // Swap the data, not the nodes
                swap(i->name, j->name);
                swap(i->score, j->score);
            }

            j = j->next;
        }

        i = i->next;
    }
}

void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << "Team: " << temp->name
             << " Goal: " << temp->score
             << endl;

        temp = temp->next;
    }
}

int main() {
    insert("France", 54);
    insert("Brazil", 62);
    insert("Japan", 36);

    sort();
    display();

    return 0;
}
