#include<iostream>
using namespace std;

void swap ( int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition ( int *arr, int lb, int ub)
{
    int pivot = *(arr+lb);
    int start = lb;
    int end = ub;

    while(start<end)
    {
        while(start <= ub && arr[start] <= pivot)
        {
            start++;
        }
        while(arr[end] > pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(arr[start], arr[end]);
        }
    }

    swap(arr[lb], arr[end]);
    return end;
}

void quickSort(int * arr, int lb, int ub)
{
    if( lb<ub)
    {
        int loc = Partition(arr, lb, ub);
        quickSort(&arr[0], lb, loc-1);
        quickSort(&arr[0], loc+1, ub);
    }
}

void display(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<"Array ("<<i+1<<"): "<<*(arr+i);
        cout<<endl;
    }
}

int main()
{   
    int size = 5;
    int arr[] = {40, 20, 10, 50, 30};
    quickSort(&arr[0], 0, size-1);
    display(&arr[0], size);
}
