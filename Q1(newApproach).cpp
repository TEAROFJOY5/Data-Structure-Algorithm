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

    Node* prev1 = NULL;
    Node* curr1 = head;

    while (curr1 != NULL) {
        Node* prev2 = curr1;
        Node* curr2 = curr1->next;

        while (curr2 != NULL) {

            if (curr1->score < curr2->score) {

                // curr1 and curr2 are adjacent
                if (curr1->next == curr2) {
                    curr1->next = curr2->next;
                    curr2->next = curr1;

                    if (prev1 == NULL)
                        head = curr2;
                    else
                        prev1->next = curr2;

                    // Update pointers
                    Node* temp = curr1;
                    curr1 = curr2;
                    curr2 = temp;
                }
            }

            prev2 = curr2;
            curr2 = curr2->next;
        }

        prev1 = curr1;
        curr1 = curr1->next;
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
