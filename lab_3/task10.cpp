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

void copyArray(int *arr, int *copy, int size)
{
    for(int i=0; i<size; i++)
        {
            copy[i] = arr[i];
        }
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

    cout<<"Sorted Array:"<<endl;
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

    cout<<"Sorted Array:"<<endl;
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

    cout<<"Sorted Array:"<<endl;
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

    cout<<"Sorted Array:"<<endl;
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

    cout<<"Sorted Array:"<<endl;
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
                    cout<<"Comparisons: "<<comparisons<<endl;
                    return i;
                }
        }

    cout<<"Comparisons: "<<comparisons<<endl;
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
                    cout<<"Comparisons: "<<comparisons<<endl;
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

    cout<<"Comparisons: "<<comparisons<<endl;
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
                            cout<<"Estimated Position: "<<left<<endl;
                            cout<<"Comparisons: "<<comparisons<<endl;
                            return left;
                        }
                    else
                        {
                            cout<<"Estimated Position: "<<left<<endl;
                            cout<<"Comparisons: "<<comparisons<<endl;
                            return -1;
                        }
                }

            int pos = left + ((search-arr[left])*(right-left))/(arr[right]-arr[left]);

            cout<<"Estimated Position: "<<pos<<endl;

            comparisons++;

            if(arr[pos] == search)
                {
                    cout<<"Comparisons: "<<comparisons<<endl;
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

    cout<<"Comparisons: "<<comparisons<<endl;
    return -1;
}

void complexity()
{
    cout<<"\nComplexity Comparison:"<<endl;
    cout<<"Algorithm        Best        Average       Worst        Space"<<endl;
    cout<<"Bubble Sort      O(n)        O(n^2)        O(n^2)       O(1)"<<endl;
    cout<<"Selection Sort   O(n^2)      O(n^2)        O(n^2)       O(1)"<<endl;
    cout<<"Insertion Sort   O(n)        O(n^2)        O(n^2)       O(1)"<<endl;
    cout<<"Shell Sort       O(n log n)  O(n log^2 n)  O(n^2)       O(1)"<<endl;
    cout<<"Comb Sort        O(n log n)  O(n^2)        O(n^2)       O(1)"<<endl;
    cout<<"Linear Search    O(1)        O(n)          O(n)         O(1)"<<endl;
    cout<<"Binary Search    O(1)        O(log n)      O(log n)     O(1)"<<endl;
    cout<<"Interpolation    O(1)        O(log log n)  O(n)         O(1)"<<endl;
}

int main()
{
    int size;

    cout<<"How many student marks you want to enter: ";
    cin>>size;

    int original[size];
    int arr[size];

    cout<<"\nEnter student marks: ";
    for(int i=0; i<size; i++)
        {
            cin>>original[i];
        }

    cout<<"\nOriginal Array:"<<endl;
    displayingArr(original,size);

    int choice;
    int search;
    int result;

    do
        {
            cout<<"\n===== MENU ====="<<endl;
            cout<<"1. Bubble Sort"<<endl;
            cout<<"2. Selection Sort"<<endl;
            cout<<"3. Insertion Sort"<<endl;
            cout<<"4. Shell Sort"<<endl;
            cout<<"5. Comb Sort"<<endl;
            cout<<"6. Linear Search"<<endl;
            cout<<"7. Binary Search"<<endl;
            cout<<"8. Interpolation Search"<<endl;
            cout<<"9. Complexity Comparison"<<endl;
            cout<<"10. Exit"<<endl;

            cout<<"Enter your choice: ";
            cin>>choice;

            if(choice>=1 && choice<=5)
                {
                    copyArray(original,arr,size);

                    if(choice==1)
                        {
                            cout<<"\nBubble Sort"<<endl;
                            bubbleSort(arr,size);

                            cout<<"Appropriate for nearly sorted data because its best case is O(n)."<<endl;
                        }
                    else if(choice==2)
                        {
                            cout<<"\nSelection Sort"<<endl;
                            selectionSort(arr,size);

                            cout<<"Appropriate when the number of swaps should be kept low."<<endl;
                        }
                    else if(choice==3)
                        {
                            cout<<"\nInsertion Sort"<<endl;
                            insertionSort(arr,size);

                            cout<<"Appropriate for nearly sorted data because its best case is O(n)."<<endl;
                        }
                    else if(choice==4)
                        {
                            cout<<"\nShell Sort"<<endl;
                            shellSort(arr,size);

                            cout<<"Appropriate for larger or unsorted data because it reduces the gap gradually."<<endl;
                        }
                    else if(choice==5)
                        {
                            cout<<"\nComb Sort"<<endl;
                            combSort(arr,size);

                            cout<<"Appropriate for unsorted data because it reduces distant inversions."<<endl;
                        }
                }
            else if(choice==6)
                {
                    cout<<"\nLinear Search"<<endl;
                    cout<<"Sorting Required: No"<<endl;

                    cout<<"Enter value to search: ";
                    cin>>search;

                    result = linearSearch(original,size,search);

                    if(result != -1)
                        {
                            cout<<"Value found at index: "<<result<<endl;
                        }
                    else
                        {
                            cout<<"-1"<<endl;
                            cout<<"Value does not exist."<<endl;
                        }

                    cout<<"Linear Search is appropriate when data is unsorted or only one search is required."<<endl;
                }
            else if(choice==7)
                {
                    copyArray(original,arr,size);
                    shellSort(arr,size);

                    cout<<"\nBinary Search"<<endl;
                    cout<<"Sorting Required: Yes"<<endl;

                    cout<<"Enter value to search: ";
                    cin>>search;

                    result = binarySearch(arr,size,search);

                    if(result != -1)
                        {
                            cout<<"Value found at index: "<<result<<endl;
                        }
                    else
                        {
                            cout<<"-1"<<endl;
                            cout<<"Value does not exist."<<endl;
                        }

                    cout<<"Binary Search is appropriate for sorted data."<<endl;
                }
            else if(choice==8)
                {
                    copyArray(original,arr,size);
                    shellSort(arr,size);

                    cout<<"\nInterpolation Search"<<endl;
                    cout<<"Sorting Required: Yes"<<endl;
                    cout<<"Data should be approximately uniformly distributed."<<endl;

                    cout<<"Enter value to search: ";
                    cin>>search;

                    result = interpolationSearch(arr,size,search);

                    if(result != -1)
                        {
                            cout<<"Value found at index: "<<result<<endl;
                        }
                    else
                        {
                            cout<<"-1"<<endl;
                            cout<<"Value does not exist."<<endl;
                        }

                    cout<<"Interpolation Search is appropriate for sorted and approximately uniformly distributed data."<<endl;
                }
            else if(choice==9)
                {
                    complexity();

                    cout<<"\nTechnique Selection:"<<endl;
                    cout<<"Nearly sorted data: Insertion Sort or Bubble Sort."<<endl;
                    cout<<"Large unsorted data: Shell Sort or Comb Sort."<<endl;
                    cout<<"Unsorted searching: Linear Search."<<endl;
                    cout<<"Sorted searching: Binary Search."<<endl;
                    cout<<"Sorted and uniformly distributed data: Interpolation Search."<<endl;
                }
            else if(choice==10)
                {
                    cout<<"Program ended."<<endl;
                }
            else
                {
                    cout<<"Invalid choice."<<endl;
                }

        }while(choice!=10);

    return 0;
}
