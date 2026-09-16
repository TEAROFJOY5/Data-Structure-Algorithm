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

void combSort(int *arr, int size)
{
    int gap = size;
    float shrink = 1.3;
    bool swapped = true;

    while(gap != 1 || swapped)
        {
            gap = gap / shrink;

            if(gap < 1)
                {
                    gap = 1;
                }

            swapped = false;

            cout<<"Gap: "<<gap<<endl;

            for(int i=0; i+gap<size; i++)
                {
                    if(arr[i]>arr[i+gap])
                        {
                            int temp = arr[i];
                            arr[i] = arr[i+gap];
                            arr[i+gap] = temp;
                            swapped = true;
                        }
                }
        }
}

int main()
{
    int size;
    cout<<"How many product codes you want to enter: ";
    cin>>size;

    int arr[size];

    cout<<"\nEnter elements in the array: ";
    for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }

    cout<<"Array Before sort:"<<endl;
    displayingArr(arr,size);

    combSort(&arr[0],size);

    cout<<"Array After sort:"<<endl;
    displayingArr(arr,size);
}
