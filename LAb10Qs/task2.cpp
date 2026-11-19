#include<iostream>
using namespace std;
struct Process
{ 
   int pid; 
   int priority; 
    Process* next; 
};
class ProcessHeap {
 public:
 	Process* arr[100] ;
	int capacity;
	int size;
	int parent(int i) { return (i - 1) / 2; }
	int leftChild(int i) { return (2 * i) + 1; }
	int rightChild(int i) { return (2 * i) + 2; }
void swapVal(int& a, int& b) { int t = a; a = b; b = t; }
 void heapifyUp(int i) {
	while (i > 0 && arr[parent(i)] < arr[i]) {
  	  swapVal(arr[parent(i)], arr[i]);
      i = parent(i);
    }
}

void heapifyDown(int i) {
 while (true) {
   int largest = i;
   int l = leftChild(i);
   int r = rightChild(i);
   if (l < size && arr[l] > arr[largest]) largest = l;
   if (r < size && arr[r] > arr[largest]) largest = r;
   if (largest == i) break;
   swapVal(arr[i], arr[largest]);
   i = largest;
 }
}
 public:
	ProcessHeap(int cap) : capacity(cap), size(0) { arr = new int[capacity]; }
	~ProcessHeap() { delete[] arr; }
  bool isEmpty() { return size == 0; }
  bool isFull() { return size == capacity; }
  void addProcess(int pid, int priority) {
  if (isFull()) { cout <<"Heap is full!"<< endl; return; }
  arr[size] = pid; // place at the end
   size++;
   heapifyUp(size - 1); // fix the heap property
}
int peekNext() {
   if (isEmpty()) { cout <<"Heap is empty!"<< endl; return -1; }
   return arr[0];
}
int deleteMax() {
  if (isEmpty()) { cout  <<"Heap is empty!&quot; "<< endl; return -1; }
  int top = arr[0];
  arr[0] = arr[size - 1]; 
  size--;
  heapifyDown(0);
   return top;
 }
 void buildHeap(int a[], int n) {
 if (n &gt; capacity) { cout <<"Array too large!" << endl; return; }
 for (int i = 0; i < n; i++) arr[i] = a[i];
 size = n;
 for (int i = n / 2 - 1; i >= 0; i--) // start from first non-leaf
 heapifyDown(i);
 }
 void display() {
  for (int i = 0; i < size; i++) cout<< arr[i] << " ";
 cout << endl;
 }
};	

int main()
{
  ProcessHeap* hp[5];
  hp.addProcess(1,5);
  hp.addProcess(2,9);	
  hp.addProcess(3,2);
  hp.addProcess(4,9);
  hp.addProcess(5,7);
  display():
  	
}
