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

void linearSearch(int *arr, int size, int search)
{
    int comparisons = 0;
    bool found = false;

    cout<<"Sorting necessary: No, Linear Search can be applied on an unsorted array."<<endl;

    for(int i=0; i<size; i++)
        {
            comparisons++;

            if(arr[i] == search)
                {
                    cout<<"Roll number found at index: "<<i<<endl;
                    cout<<"Comparisons required: "<<comparisons<<endl;
                    found = true;
                    break;
                }
        }

    if(found == false)
        {
            cout<<"Roll number does not exist."<<endl;
            cout<<"Comparisons required: "<<comparisons<<endl;
        }
}

int main()
{
    int size;
    cout<<"How many student roll numbers you want to enter: ";
    cin>>size;

    int arr[size];

    cout<<"\nEnter roll numbers in the array: ";
    for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }

    cout<<"Array:"<<endl;
    displayingArr(arr,size);

    int search;
    cout<<"Enter roll number to search: ";
    cin>>search;

    linearSearch(&arr[0],size,search);
}
