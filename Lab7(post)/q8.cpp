/*
Task 8: The given Radix Sort assumes all numbers are non-negative.
Run the given code on {-5, 170, -45, 802, 24, -2, 66, 0}. mention (in comments) exactly what goes wrong. Look at the expression (arr[i] / place) % 10: what values can it produce for a negative number and what does the count array do with them?
Without changing countingSort's core logic, design a way to sort this array correctly using Radix Sort. You may split the array, transform values, or call radixSort more than once, but each negative number must end up in the correct position.
Test on the array above and on an all-negative array like {-10, -3, -250, -7}. Show your outputs.
State clearly in 3 to 4 lines the idea of your solution and why it preserves correct ordering for the negatives (remember that -250 is smaller than -3 even though it has more digits).

*/

#include<iostream>
using namespace std;

void display(int *arr, int size)
{
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

void countingSort(int *arr, int size, int place)
{
    int *output = new int[size];
    int count[10] = {0};

    for(int i=0; i<size; i++)
        count[(arr[i]/place)%10]++;

    for(int i=1; i<10; i++)
        count[i] = count[i] + count[i-1];

    for(int i=size-1; i>=0; i--)
    {
        int digit = (arr[i]/place)%10;
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }

    for(int i=0; i<size; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int *arr, int size)
{
    int max = arr[0];

    for(int i=1; i<size; i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }

    for(int place=1; max/place>0; place*=10)
        countingSort(arr, size, place);
}

void sortNegative(int *arr, int size)
{
    for(int i=0; i<size; i++)
        arr[i] = -arr[i];

    radixSort(arr, size);

    for(int i=0; i<size/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }

    for(int i=0; i<size; i++)
        arr[i] = -arr[i];
}

void signedRadixSort(int *arr, int size)
{
    int negativeCount = 0;
    int positiveCount = 0;

    for(int i=0; i<size; i++)
    {
        if(arr[i]<0)
            negativeCount++;
        else
            positiveCount++;
    }

    int *negative = new int[negativeCount];
    int *positive = new int[positiveCount];

    int n=0;
    int p=0;

    for(int i=0; i<size; i++)
    {
        if(arr[i]<0)
            negative[n++] = arr[i];
        else
            positive[p++] = arr[i];
    }

    if(negativeCount>0)
        sortNegative(negative, negativeCount);

    if(positiveCount>0)
        radixSort(positive, positiveCount);

    int k=0;

    for(int i=0; i<negativeCount; i++)
        arr[k++] = negative[i];

    for(int i=0; i<positiveCount; i++)
        arr[k++] = positive[i];

    delete[] negative;
    delete[] positive;
}

int main()
{
    int arr[] = {-5, 170, -45, 802, 24, -2, 66, 0};
    int size = 8;

    cout<<"Original Array:"<<endl;
    display(arr, size);

    cout<<"Sorted Array:"<<endl;
    signedRadixSort(arr, size);
    display(arr, size);

    int arr2[] = {-10, -3, -250, -7};
    int size2 = 4;

    cout<<"\nAll Negative Array:"<<endl;
    display(arr2, size2);

    cout<<"Sorted Array:"<<endl;
    signedRadixSort(arr2, size2);
    display(arr2, size2);
}
