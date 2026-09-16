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

void selectionSort(int *arr, int size)
{
    for(int i=0; i<size-1; i++)
        {
            int minIndex = i;

            for(int j=i+1; j<size; j++)
                {
                    if(arr[j]<arr[minIndex])
                        {
                            minIndex = j;
                        }
                }

            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
}

void binarySearch(int *arr, int size, int search)
{
    int left = 0;
    int right = size - 1;
    bool found = false;

    while(left<=right)
        {
            int mid = (left+right)/2;

            cout<<"Left: "<<left<<" Right: "<<right<<" Mid: "<<mid<<endl;

            if(arr[mid] == search)
                {
                    cout<<"Product ID found at index: "<<mid<<endl;
                    found = true;
                    break;
                }
            else if(arr[mid]<search)
                {
                    left = mid + 1;
                }
            else
                {
                    right = mid - 1;
                }
        }

    if(found == false)
        {
            cout<<"Product ID does not exist."<<endl;
        }
}

int main()
{
    int size;
    cout<<"How many product IDs you want to enter: ";
    cin>>size;

    int arr[size];

    cout<<"\nEnter product IDs in the array: ";
    for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }

    cout<<"Original Array:"<<endl;
    displayingArr(arr,size);

    selectionSort(&arr[0],size);

    cout<<"Sorted Array:"<<endl;
    displayingArr(arr,size);

    int search;
    cout<<"Enter product ID to search: ";
    cin>>search;

    binarySearch(&arr[0],size,search);
}
