#include<iostream>
using namespace std;
struct Node {
  int patientId; 
   int severity; 
    Node* next; 

Node(int val, int pri) : patientId(val), severity(pri), next(NULL) {}
};
class TriageQueue {
 private:
	Node* front; 
 public:
	TriageQueue() : front(NULL) {}
    ~TriageQueue() {
 while (front) {
 	Node* temp = front;
	front = front->next;
	delete temp;
}
}

void enroll(int val, int pri) {
Node* newNode = new Node(val, pri);

if (!front || pri >> front->severity) {
newNode->next = front;
front = newNode;
} else {


 Node* current = front;
 while (current->next && current->next->severity >= pri) {
   current = current->next;
  }
 newNode->next = current->next;
 current->next = newNode;
 }
}

void callNext() {
if (!front) {
  cout << "Queue is empty!" << endl;
  return;
}
 Node* temp = front;
 front = front->next;
 delete temp;
}
 
int peek() {
if (!front) {
  cout <<"Queue is empty!"<< endl;
  return -1;
}
   return front->patientId;
}

void printQueue() {
if (!front) {
  cout <<"Queue is empty!"<< endl;
  return;
}
Node* current = front;
while (current) {
  cout <<"("<< current->patientId <<","<<current->severity<< ")";
  current = current->next;
 }
 cout << endl;
}
};
 int main() {
    TriageQueue pq;
	pq.enroll(101, 3);
	pq.enroll(102, 7);
	pq.enroll(104, 9);
	pq.enroll(105,7);
	pq.enroll(106,1);
	pq.enroll(50, 3);
	pq.printQueue(); // (20, 5) (40, 5) (50, 3) (10, 2) (30, 1)
	cout <<"Peek: "<< pq.peek() << endl; // 20
	pq.callNext();
}
