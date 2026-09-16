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

void shellSort(int *arr, int size)
{
    int gap = size / 2;
    int pass = 0;

    while(gap >= 1)
        {
            for(int i=gap; i<size; i++)
                {
                    int temp = arr[i];
                    int j = i;

                    while(j>=gap && arr[j-gap]>temp)
                        {
                            arr[j] = arr[j-gap];
                            j = j-gap;
                        }

                    arr[j] = temp;
                }

            pass++;
            cout<<"Array after gap "<<gap<<" pass"<<endl;
            displayingArr(arr,size);

            gap = gap / 2;
        }
}

int main()
{
    int size;
    cout<<"How many employee performance scores you want to enter: ";
    cin>>size;

    int arr[size];

    cout<<"\nEnter elements in the array: ";
    for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }

    cout<<"Array Before sort:"<<endl;
    displayingArr(arr,size);

    shellSort(&arr[0],size);

    cout<<"Array After sort:"<<endl;
    displayingArr(arr,size);
}
