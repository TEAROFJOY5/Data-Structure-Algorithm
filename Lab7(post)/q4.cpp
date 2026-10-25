/*
Task 4: The given Quick Sort always uses the right-most element as pivot.
Run it on the already sorted array {10, 20, 30, 40, 50} and on {40, 20, 10, 50, 30}. Using the counters from Task 1, compare the number of comparisons and partition calls. Also track the maximum recursion depth (increase a counter when entering quickSort, decrease it when leaving).
Explain in your own comments (in programs), using what each partition produces for the sorted array, why this input is the worst case.
The manual says "Choose any index value as pivot". Without changing the partition loop, modify quickSort so that it first swaps the middle element into position high, and then runs the same partition. Run the sorted array again and compare the counters and depth.
Try {50, 40, 30, 20, 10}. Does the middle pivot fix this input too?

*/
#include<iostream>
using namespace std;

int comparisons = 0;
int partitionCalls = 0;
int depth = 0;
int maxDepth = 0;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int *arr, int lb, int ub)
{
    partitionCalls++;

    int pivot = *(arr+ub);
    int start = lb;
    int end = ub-1;

    while(start<=end)
    {
        while(start<=end && arr[start]<=pivot)
        {
            comparisons++;
            start++;
        }

        while(start<=end && arr[end]>pivot)
        {
            comparisons++;
            end--;
        }

        if(start<end)
        {
            comparisons++;
            swap(arr[start], arr[end]);
        }
    }

    swap(arr[start], arr[ub]);
    return start;
}

void quickSort(int *arr, int lb, int ub)
{
    depth++;

    if(depth>maxDepth)
    {
        maxDepth = depth;
    }

    if(lb<ub)
    {
        int loc = Partition(arr, lb, ub);
        quickSort(&arr[0], lb, loc-1);
        quickSort(&arr[0], loc+1, ub);
    }

    depth--;
}

void display(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<"Array ("<<i+1<<"): "<<*(arr+i)<<endl;
    }
}

void resetCounters()
{
    comparisons = 0;
    partitionCalls = 0;
    depth = 0;
    maxDepth = 0;
}

int main()
{
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {40, 20, 10, 50, 30};
    int arr3[] = {10, 20, 30, 40, 50};
    int arr4[] = {50, 40, 30, 20, 10};

    int size = 5;

    cout<<"Sorted Array with Right Pivot:"<<endl;
    quickSort(arr1, 0, size-1);
    display(arr1, size);
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Partition Calls: "<<partitionCalls<<endl;
    cout<<"Maximum Depth: "<<maxDepth<<endl;

    resetCounters();

    cout<<"\nUnsorted Array with Right Pivot:"<<endl;
    quickSort(arr2, 0, size-1);
    display(arr2, size);
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Partition Calls: "<<partitionCalls<<endl;
    cout<<"Maximum Depth: "<<maxDepth<<endl;

    resetCounters();

    cout<<"\nSorted Array with Middle Pivot:"<<endl;
    quickSort(arr3, 0, size-1);
    display(arr3, size);
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Partition Calls: "<<partitionCalls<<endl;
    cout<<"Maximum Depth: "<<maxDepth<<endl;

    resetCounters();

    cout<<"\nReverse Sorted Array with Middle Pivot:"<<endl;
    quickSort(arr4, 0, size-1);
    display(arr4, size);
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Partition Calls: "<<partitionCalls<<endl;
    cout<<"Maximum Depth: "<<maxDepth<<endl;
}
