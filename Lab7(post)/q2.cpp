/*
Task 2: Using the given Radix Sort code on {170, 45, 75, 90, 802, 24, 2, 66}:
Modify radixSort so it prints the array after every call to countingSort, along with the place value being processed.
Now test with {5, 3, 9, 1, 7}. How many passes happened? Then test with {5, 3, 9, 1, 700}. How many passes happened now, and why did one big number change the work for everyone?

*/

#include<iostream>
using namespace std;

void display(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

void countingSort(int *arr, int size, int place)
{
    int output[size];
    int count[10] = {0};

    for(int i=0; i<size; i++)
    {
        count[(arr[i]/place)%10]++;
    }

    for(int i=1; i<10; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    for(int i=size-1; i>=0; i--)
    {
        int digit = (arr[i]/place)%10;
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }

    for(int i=0; i<size; i++)
    {
        arr[i] = output[i];
    }

    cout<<"Place value "<<place<<": ";
    display(arr, size);
}

void radixSort(int *arr, int size)
{
    int max = arr[0];

    for(int i=1; i<size; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }

    for(int place=1; max/place>0; place*=10)
    {
        countingSort(arr, size, place);
    }
}

int main()
{
    int size = 8;
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};

    cout<<"Original Array: ";
    display(arr, size);

    radixSort(arr, size);

    cout<<"Sorted Array: ";
    display(arr, size);

    int arr2[] = {5, 3, 9, 1, 7};
    int size2 = 5;

    cout<<"\nSecond Array:"<<endl;
    radixSort(arr2, size2);

    int arr3[] = {5, 3, 9, 1, 700};
    int size3 = 5;

    cout<<"\nThird Array:"<<endl;
    radixSort(arr3, size3);
}
