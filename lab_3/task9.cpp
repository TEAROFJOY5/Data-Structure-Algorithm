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

void bubbleSort(int *arr, int size)
{
    int comparisons = 0;
    int swaps = 0;

    for(int i=0; i<size-1; i++)
        {
            bool swapped = false;

            for(int j=0; j<size-i-1; j++)
                {
                    comparisons++;

                    if(arr[j]>arr[j+1])
                        {
                            int temp = arr[j];
                            arr[j] = arr[j+1];
                            arr[j+1] = temp;
                            swaps++;
                            swapped = true;
                        }
                }

            if(swapped == false)
                {
                    break;
                }
        }

    cout<<"Bubble Sort:"<<endl;
    displayingArr(arr,size);
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps: "<<swaps<<endl;
}

void selectionSort(int *arr, int size)
{
    int comparisons = 0;
    int swaps = 0;

    for(int i=0; i<size-1; i++)
        {
            int minIndex = i;

            for(int j=i+1; j<size; j++)
                {
                    comparisons++;

                    if(arr[j]<arr[minIndex])
                        {
                            minIndex = j;
                        }
                }

            if(minIndex != i)
                {
                    int temp = arr[i];
                    arr[i] = arr[minIndex];
                    arr[minIndex] = temp;
                    swaps++;
                }
        }

    cout<<"Selection Sort:"<<endl;
    displayingArr(arr,size);
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps: "<<swaps<<endl;
}

void insertionSort(int *arr, int size)
{
    int comparisons = 0;
    int swaps = 0;

    for(int i=1; i<size; i++)
        {
            int temp = arr[i];
            int j = i-1;

            while(j>=0)
                {
                    comparisons++;

                    if(arr[j]>temp)
                        {
                            arr[j+1] = arr[j];
                            j--;
                            swaps++;
                        }
                    else
                        {
                            break;
                        }
                }

            arr[j+1] = temp;
        }

    cout<<"Insertion Sort:"<<endl;
    displayingArr(arr,size);
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps/Shifts: "<<swaps<<endl;
}

void shellSort(int *arr, int size)
{
    int comparisons = 0;
    int swaps = 0;

    int gap = size/2;

    while(gap>=1)
        {
            for(int i=gap; i<size; i++)
                {
                    int temp = arr[i];
                    int j = i;

                    while(j>=gap)
                        {
                            comparisons++;

                            if(arr[j-gap]>temp)
                                {
                                    arr[j] = arr[j-gap];
                                    j = j-gap;
                                    swaps++;
                                }
                            else
                                {
                                    break;
                                }
                        }

                    arr[j] = temp;
                }

            gap = gap/2;
        }

    cout<<"Shell Sort:"<<endl;
    displayingArr(arr,size);
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps/Shifts: "<<swaps<<endl;
}

void combSort(int *arr, int size)
{
    int comparisons = 0;
    int swaps = 0;
    int gap = size;
    float shrink = 1.3;
    bool swapped = true;

    while(gap!=1 || swapped)
        {
            gap = gap/shrink;

            if(gap<1)
                {
                    gap = 1;
                }

            swapped = false;

            for(int i=0; i+gap<size; i++)
                {
                    comparisons++;

                    if(arr[i]>arr[i+gap])
                        {
                            int temp = arr[i];
                            arr[i] = arr[i+gap];
                            arr[i+gap] = temp;
                            swaps++;
                            swapped = true;
                        }
                }
        }

    cout<<"Comb Sort:"<<endl;
    displayingArr(arr,size);
    cout<<"Comparisons: "<<comparisons<<endl;
    cout<<"Swaps: "<<swaps<<endl;
}

int linearSearch(int *arr, int size, int search)
{
    int comparisons = 0;

    for(int i=0; i<size; i++)
        {
            comparisons++;

            if(arr[i] == search)
                {
                    cout<<"Linear Search Comparisons: "<<comparisons<<endl;
                    return i;
                }
        }

    cout<<"Linear Search Comparisons: "<<comparisons<<endl;
    return -1;
}

int binarySearch(int *arr, int size, int search)
{
    int left = 0;
    int right = size-1;
    int comparisons = 0;

    while(left<=right)
        {
            int mid = (left+right)/2;

            comparisons++;

            cout<<"Left: "<<left<<" Right: "<<right<<" Mid: "<<mid<<endl;

            if(arr[mid] == search)
                {
                    cout<<"Binary Search Comparisons: "<<comparisons<<endl;
                    return mid;
                }
            else if(arr[mid]<search)
                {
                    left = mid+1;
                }
            else
                {
                    right = mid-1;
                }
        }

    cout<<"Binary Search Comparisons: "<<comparisons<<endl;
    return -1;
}

int interpolationSearch(int *arr, int size, int search)
{
    int left = 0;
    int right = size-1;
    int comparisons = 0;

    while(left<=right && search>=arr[left] && search<=arr[right])
        {
            if(arr[left] == arr[right])
                {
                    comparisons++;

                    if(arr[left] == search)
                        {
                            cout<<"Interpolation Search Comparisons: "<<comparisons<<endl;
                            return left;
                        }
                    else
                        {
                            cout<<"Interpolation Search Comparisons: "<<comparisons<<endl;
                            return -1;
                        }
                }

            int pos = left + ((search-arr[left])*(right-left))/(arr[right]-arr[left]);

            cout<<"Estimated Position: "<<pos<<endl;

            comparisons++;

            if(arr[pos] == search)
                {
                    cout<<"Interpolation Search Comparisons: "<<comparisons<<endl;
                    return pos;
                }
            else if(arr[pos]<search)
                {
                    left = pos+1;
                }
            else
                {
                    right = pos-1;
                }
        }

    cout<<"Interpolation Search Comparisons: "<<comparisons<<endl;
    return -1;
}

int main()
{
    int size;

    cout<<"How many numerical records you want to enter: ";
    cin>>size;

    int original[size];
    int arr1[size];
    int arr2[size];
    int arr3[size];
    int arr4[size];
    int arr5[size];

    cout<<"\nEnter elements in the array: ";
    for(int i=0; i<size; i++)
        {
            cin>>original[i];

            arr1[i] = original[i];
            arr2[i] = original[i];
            arr3[i] = original[i];
            arr4[i] = original[i];
            arr5[i] = original[i];
        }

    cout<<"\nOriginal Array:"<<endl;
    displayingArr(original,size);

    cout<<"\n";

    bubbleSort(arr1,size);
    cout<<"\n";

    selectionSort(arr2,size);
    cout<<"\n";

    insertionSort(arr3,size);
    cout<<"\n";

    shellSort(arr4,size);
    cout<<"\n";

    combSort(arr5,size);
    cout<<"\n";

    cout<<"Searching will be performed on the sorted array."<<endl;

    int search;
    cout<<"Enter value to search: ";
    cin>>search;

    cout<<"\nLinear Search:"<<endl;
    int result = linearSearch(arr4,size,search);

    if(result != -1)
        {
            cout<<"Value found at index: "<<result<<endl;
        }
    else
        {
            cout<<"Value does not exist."<<endl;
        }

    cout<<"\nBinary Search:"<<endl;
    result = binarySearch(arr4,size,search);

    if(result != -1)
        {
            cout<<"Value found at index: "<<result<<endl;
        }
    else
        {
            cout<<"Value does not exist."<<endl;
        }

    cout<<"\nInterpolation Search:"<<endl;
    result = interpolationSearch(arr4,size,search);

    if(result != -1)
        {
            cout<<"Value found at index: "<<result<<endl;
        }
    else
        {
            cout<<"Value does not exist."<<endl;
        }

    cout<<"\nComplexity Comparison:"<<endl;

    cout<<"Algorithm        Best       Average      Worst       Space"<<endl;
    cout<<"Bubble Sort      O(n)       O(n^2)       O(n^2)      O(1)"<<endl;
    cout<<"Selection Sort   O(n^2)     O(n^2)       O(n^2)      O(1)"<<endl;
    cout<<"Insertion Sort   O(n)       O(n^2)       O(n^2)      O(1)"<<endl;
    cout<<"Shell Sort       O(n log n) O(n log^2 n) O(n^2)      O(1)"<<endl;
    cout<<"Comb Sort        O(n log n) O(n^2)       O(n^2)      O(1)"<<endl;
    cout<<"Linear Search    O(1)       O(n)         O(n)        O(1)"<<endl;
    cout<<"Binary Search    O(1)       O(log n)     O(log n)    O(1)"<<endl;
    cout<<"Interpolation    O(1)       O(log log n) O(n)        O(1)"<<endl;

    cout<<"\nMost appropriate techniques:"<<endl;

    if(size<=10)
        {
            cout<<"For a small array, Insertion Sort is appropriate."<<endl;
        }
    else
        {
            cout<<"For a large array, Shell Sort is appropriate."<<endl;
        }

    cout<<"For searching, Binary Search is appropriate because the data is sorted."<<endl;
    cout<<"Interpolation Search is appropriate when the sorted data is approximately uniformly distributed."<<endl;
}
