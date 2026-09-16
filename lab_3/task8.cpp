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

int interpolationSearch(int *arr, int size, int search)
{
    int left = 0;
    int right = size - 1;

    while(left<=right && search>=arr[left] && search<=arr[right])
        {
            if(arr[left] == arr[right])
                {
                    cout<<"Estimated position: "<<left<<endl;

                    if(arr[left] == search)
                        {
                            return left;
                        }
                    else
                        {
                            return -1;
                        }
                }

            int pos = left + ((search-arr[left])*(right-left))/(arr[right]-arr[left]);

            cout<<"Estimated position: "<<pos<<endl;

            if(arr[pos] == search)
                {
                    return pos;
                }
            else if(arr[pos] < search)
                {
                    left = pos + 1;
                }
            else
                {
                    right = pos - 1;
                }
        }

    return -1;
}

int main()
{
    int size;
    cout<<"How many student scores you want to enter: ";
    cin>>size;

    int arr[size];

    cout<<"\nEnter scores in ascending order: ";
    for(int i=0; i<size; i++)
        {
            cin>>arr[i];
        }

    cout<<"Array:"<<endl;
    displayingArr(arr,size);

    int search;
    cout<<"Enter score to search: ";
    cin>>search;

    int result = interpolationSearch(&arr[0],size,search);

    if(result != -1)
        {
            cout<<"Score found at index: "<<result<<endl;
        }
    else
        {
            cout<<"-1"<<endl;
        }
}
