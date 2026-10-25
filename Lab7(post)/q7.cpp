/*
  Task 7: Given {19, 7, 15, 12, 16, 18, 4, 11, 13}, you are asked to find the k-th smallest element without sorting the whole array.
Reuse the partition step of the given Quick Sort. After one partition, the pivot is at its final index p. Using only p and k, decide whether the answer is the pivot, lies in the left part, or lies in the right part.
Write a function kthSmallest(arr, low, high, k) that recurses into only one side each time.
Run it for k = 1, k = 5 (the median) and k = 9. Print the pivot index at every step.
Compare how many elements were examined (count comparisons) against doing the complete Quick Sort and then reading index k - 1.
Using Quick Sort's final structure, mention (in comments) why finding the median this way can be faster than fully sorting, but is not guaranteed to be if the pivot choices are bad.

*/

#include<iostream>
using namespace std;

int comparisons = 0;
int partitionCalls = 0;
int quickComparisons = 0;
int quickPartitionCalls = 0;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int *arr, int low, int high, bool quick)
{
    if(quick)
        quickPartitionCalls++;
    else
        partitionCalls++;

    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++)
    {
        if(quick)
            quickComparisons++;
        else
            comparisons++;

        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

int kthSmallest(int *arr, int low, int high, int k)
{
    if(low<=high)
    {
        int p = Partition(arr, low, high, false);

        cout<<"Pivot index: "<<p<<", Pivot value: "<<arr[p]<<endl;

        if(p==k-1)
            return arr[p];

        else if(p>k-1)
            return kthSmallest(arr, low, p-1, k);

        else
            return kthSmallest(arr, p+1, high, k);
    }

    return -1;
}

void quickSort(int *arr, int low, int high)
{
    if(low<high)
    {
        int p = Partition(arr, low, high, true);

        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

void display(int *arr, int size)
{
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int main()
{
    int original[] = {19, 7, 15, 12, 16, 18, 4, 11, 13};
    int size = 9;

    int arr1[9];
    int arr2[9];
    int arr3[9];

    for(int i=0; i<size; i++)
    {
        arr1[i] = original[i];
        arr2[i] = original[i];
        arr3[i] = original[i];
    }

    cout<<"Finding 1st Smallest:"<<endl;
    cout<<"Answer: "<<kthSmallest(arr1, 0, size-1, 1)<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Partition Calls: "<<partitionCalls<<endl;

    comparisons = 0;
    partitionCalls = 0;

    cout<<"\nFinding 5th Smallest:"<<endl;
    cout<<"Answer: "<<kthSmallest(arr2, 0, size-1, 5)<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Partition Calls: "<<partitionCalls<<endl;

    comparisons = 0;
    partitionCalls = 0;

    cout<<"\nFinding 9th Smallest:"<<endl;
    cout<<"Answer: "<<kthSmallest(arr3, 0, size-1, 9)<<endl;
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Partition Calls: "<<partitionCalls<<endl;

    cout<<"\nComplete Quick Sort:"<<endl;

    quickSort(original, 0, size-1);

    display(original, size);

    cout<<"Comparisons: "<<quickComparisons<<endl;
    cout<<"Partition Calls: "<<quickPartitionCalls<<endl;
    cout<<"5th Smallest: "<<original[4]<<endl;
}
