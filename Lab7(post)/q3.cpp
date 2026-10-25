/*
Task 3: Convert the Merge Sort pseudocode from the manual into C++ (mergeSort and merge).
Test it on {7, 3, 2, 16, 24, 4, 11, 9}.
Make your program print the divide phase and the merge phase as an indented tree. Use the recursion depth to decide the indentation, for example: split [0..7], then split [0..3], and so on, then merge [0..1] -> 3 7.
Count how many times merge was called for 8 elements. Predict the number first. Then try an array of 5 elements and a 16-element array and see whether your prediction rule still works.

*/


#include<iostream>
using namespace std;

int size = 0;
int mergeCalls = 0;

void merge(int* arr, int lb, int mid, int ub, int depth);

void MergeSort(int* arr, int lb, int ub, int depth)
{
    if(lb<ub)
    {
        for(int i=0; i<depth; i++)
            cout<<"  ";

        cout<<"Split ["<<lb<<".."<<ub<<"]"<<endl;

        int mid = (lb+ub)/2;

        MergeSort(arr, lb, mid, depth+1);
        MergeSort(arr, mid+1, ub, depth+1);

        merge(arr, lb, mid, ub, depth);
    }
}

void merge(int* arr, int lb, int mid, int ub, int depth)
{
    mergeCalls++;

    int* b = new int[ub-lb+1];

    int i = lb;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    while(j<=ub)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for(i=lb, k=0; i<=ub; i++, k++)
        arr[i] = b[k];

    for(int i=0; i<depth; i++)
        cout<<"  ";

    cout<<"Merge ["<<lb<<".."<<ub<<"] -> ";

    for(int i=lb; i<=ub; i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    delete[] b;
}

void display(int* arr, int size)
{
    for(int i=0; i<size; i++)
        cout<<*(arr+i)<<" ";

    cout<<endl;
}

int main()
{
    int arr1[] = {7, 3, 2, 16, 24, 4, 11, 9};
    int size1 = 8;

    cout<<"Predicted merge calls for 8 elements: "<<size1-1<<endl;
    cout<<"\nArray of 8 elements:"<<endl;

    MergeSort(arr1, 0, size1-1, 0);

    cout<<"Sorted Array: ";
    display(arr1, size1);
    cout<<"Actual merge calls: "<<mergeCalls<<endl;

    int arr2[] = {5, 3, 9, 1, 7};
    int size2 = 5;

    mergeCalls = 0;

    cout<<"\nPredicted merge calls for 5 elements: "<<size2-1<<endl;
    cout<<"\nArray of 5 elements:"<<endl;

    MergeSort(arr2, 0, size2-1, 0);

    cout<<"Sorted Array: ";
    display(arr2, size2);
    cout<<"Actual merge calls: "<<mergeCalls<<endl;

    int arr3[] = {16, 4, 12, 8, 1, 15, 6, 10,
                  3, 14, 7, 11, 2, 13, 5, 9};
    int size3 = 16;

    mergeCalls = 0;

    cout<<"\nPredicted merge calls for 16 elements: "<<size3-1<<endl;
    cout<<"\nArray of 16 elements:"<<endl;

    MergeSort(arr3, 0, size3-1, 0);

    cout<<"Sorted Array: ";
    display(arr3, size3);
    cout<<"Actual merge calls: "<<mergeCalls<<endl;
}
