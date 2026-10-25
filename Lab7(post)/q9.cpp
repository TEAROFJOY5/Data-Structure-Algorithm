/*
Task 9: An inversion is a pair of positions i < j with arr[i] > arr[j]. A sorted array has 0 inversions and the maximum is when the array is in reverse order.
Count the inversions for {2, 4, 1, 3, 5} and {8, 4, 2, 1}.
Write a simple brute-force counter with two loops. This is only for checking your answer.
Now modify the merge step of Merge Sort so that the final count is calculated while sorting, without any nested loop over the whole array. Think about the moment when an element of the right half is copied before the remaining elements of the left half. What does that tell you about the pairs that exist at that moment?
Test your merge-based counter against the brute-force counter on at least 5 arrays: sorted, reverse sorted, random, all equal elements and an array with duplicates. The two results must match.
Use your counter on the arrays from Task 5 ({10, 20, 30, 40, 50} and {50, 40, 30, 20, 10}). What is the relationship between the inversion count and what the given Quick Sort does on these inputs? Does a low number of inversions always mean Quick Sort (right-most pivot) is fast? Prove it with an example.

 */

#include<iostream>
using namespace std;

long long bruteForce(int *arr, int size)
{
    long long count = 0;

    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(arr[i]>arr[j])
                count++;
        }
    }

    return count;
}

long long merge(int *arr, int lb, int mid, int ub)
{
    int *b = new int[ub-lb+1];

    int i = lb;
    int j = mid+1;
    int k = 0;
    long long count = 0;

    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            count += mid-i+1;
            j++;
        }

        k++;
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

    delete[] b;

    return count;
}

long long mergeSort(int *arr, int lb, int ub)
{
    long long count = 0;

    if(lb<ub)
    {
        int mid = (lb+ub)/2;

        count += mergeSort(arr, lb, mid);
        count += mergeSort(arr, mid+1, ub);
        count += merge(arr, lb, mid, ub);
    }

    return count;
}

void testArray(int *arr, int size)
{
    int *b = new int[size];

    for(int i=0; i<size; i++)
        b[i] = arr[i];

    long long brute = bruteForce(arr, size);
    long long mergeCount = mergeSort(b, 0, size-1);

    cout<<"Array: ";

    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    cout<<"\nBrute Force: "<<brute;
    cout<<"\nMerge Sort: "<<mergeCount<<endl;

    delete[] b;
}

int main()
{
    int arr1[] = {2, 4, 1, 3, 5};
    int arr2[] = {8, 4, 2, 1};

    cout<<"Task 1:"<<endl;
    testArray(arr1, 5);
    testArray(arr2, 4);

    int sorted[] = {1, 2, 3, 4, 5};
    int reverse[] = {5, 4, 3, 2, 1};
    int random[] = {7, 2, 5, 1, 6};
    int equal[] = {4, 4, 4, 4, 4};
    int duplicates[] = {3, 1, 2, 3, 1};

    cout<<"\nTask 4:"<<endl;
    testArray(sorted, 5);
    testArray(reverse, 5);
    testArray(random, 5);
    testArray(equal, 5);
    testArray(duplicates, 5);

    int ascending[] = {10, 20, 30, 40, 50};
    int descending[] = {50, 40, 30, 20, 10};

    cout<<"\nTask 5 Arrays:"<<endl;
    testArray(ascending, 5);
    testArray(descending, 5);
}
