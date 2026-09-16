#include<iostream>
using namespace std;
void displayingArr(int arr[], int size)
{
    for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
    cout<<endl;
}
void insertionSort(int *arr, int size)
{
    int it = 0;
    for(int i =1; i<size; i++)
        {
            int temp = arr[i];
            int j = i - 1;
            while (j>=0 && arr[j]>temp)
                {
                    arr[j+1] = arr[j];
                    j--;
                }
            arr[j + 1] = temp;
            it++;
            cout<<"Array after "<<it<<" iteration"<<endl;
            displayingArr(arr,size);
        }
}
int main()
{
    int size;
    cout<< "How many temperature readings you want to enter: ";
    cin>>size;
    int arr[size];
    cout<<"\nEnter elements in the array: ";
    for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }
    cout<<"Array Before sort: "<<endl;
    displayingArr(arr,size);
    insertionSort(&arr[0],size);
    cout<<"Array After sort: "<<endl;
    displayingArr(arr,size);
}
