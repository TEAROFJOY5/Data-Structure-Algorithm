/*
Task 3: Convert the Merge Sort pseudocode from the manual into C++ (mergeSort and merge).
Test it on {7, 3, 2, 16, 24, 4, 11, 9}.
Make your program print the divide phase and the merge phase as an indented tree. Use the recursion depth to decide the indentation, for example: split [0..7], then split [0..3], and so on, then merge [0..1] -> 3 7.
Count how many times merge was called for 8 elements. Predict the number first. Then try an array of 5 elements and a 16-element array and see whether your prediction rule still works.

*/
#include<iostream>
using namespace std;
int size =0;
void merge(int* arr, int lb, int mid, int ub);

void MergeSort(int* arr, int lb, int ub)
{
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        MergeSort(arr, lb, mid);
        MergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}
void merge( int * arr, int lb, int mid, int ub)
{
    int b[size];
    int i = lb;
    int j = mid+1;
    int k = lb;
    while(i<= mid && j<= ub)
    {
        if(arr[i]<= arr[j])
        {
            b[k] = arr[i];
            i++; k++;
        }
        else
        {
            b[k] = arr[j];
            j++; k++;
        }
    }
    
    if(i>mid)
    {
        while(j<=)
    }
}
