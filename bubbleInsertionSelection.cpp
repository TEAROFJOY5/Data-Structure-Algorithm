#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int* addelements(int size){
    int *arr = new int[size];

    cout << "Enter elements: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    return arr;
}

void BubbleSort(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        bool found = false;

        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                found = true;
            }
        }

        if(!found)
            break;
    }
}
// Insertion sort
void InsertionSort(int *arr, int size){
    // Traverse through 1 to size because the first element is already sorted
    for(int i = 1; i< size; i++){
        int key = arr[i];
        int j = i-1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        for(; j >= 0 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

// Selection sort
void SelectionSort(int *arr, int size){
    // it will sort all the elements in the array except for last one.
    for ( int i =0; i <size -1; i++){
        // Find the minimum element in unsorted array
        int min_index = i ;
        for ( int j = i + 1 ; j < size ; j++){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        if (min_index != i){
            swap(arr[i], arr[min_index]);
        }
        }
    }
}
// Main function to test the sorting algorithms

int main(){
    int size, sizeS, sizeI;

    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = addelements(size);

    BubbleSort(arr, size);

    cout << "The sorted array is: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    delete[] arr;
    cout << endl;
    cout<< "Insertion Sort" << endl;
     cout << "Enter the size of the array: ";
    cin >> sizeI;   
    int *arrI = addelements(sizeI);
    InsertionSort(arrI, sizeI);
    cout << "The sorted array is: ";
    for(int i = 0; i < sizeI; i++){
        cout << arrI[i] << " ";
    }
    delete[] arrI;
    cout << endl;
    cout<< "Selection Sort" << endl;
     cout << "Enter the size of the array: ";
    cin >> sizeS;   
    int *arrS = addelements(sizeS);
    SelectionSort(arrS, sizeS);
    cout << "The sorted array is: ";
    for(int i = 0; i < sizeS; i++){
        cout << arrS[i] << " ";
    }
    delete[] arrS;
    return 0;
}
