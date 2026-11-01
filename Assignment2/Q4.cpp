
#include<iostream>
using namespace std;

void display(int H[], int n)
{
    for(int i=1; i<=n; i++)
        cout << H[i] << " ";

    cout << endl;
}

void insert(int H[], int &n, int key)
{
    n++;
    H[n] = key;

    int i = n;

    while(i > 1 && H[i] < H[i/2])
    {
        int temp = H[i];
        H[i] = H[i/2];
        H[i/2] = temp;

        display(H,n);

        i = i/2;
    }
}

int extractMin(int H[], int &n)
{
    if(n == 0)
        return -1;

    int min = H[1];

    H[1] = H[n];
    n--;

    cout << "After moving last element: ";
    display(H,n);

    int i = 1;

    while(2*i <= n)
    {
        int small = 2*i;

        if(2*i+1 <= n && H[2*i+1] < H[2*i])
            small = 2*i+1;

        if(H[i] <= H[small])
            break;

        int temp = H[i];
        H[i] = H[small];
        H[small] = temp;

        display(H,n);

        i = small;
    }

    return min;
}

void decreaseKey(int H[], int n, int index, int key)
{
    if(index < 1 || index > n || key > H[index])
        return;

    H[index] = key;

    int i = index;

    while(i > 1 && H[i] < H[i/2])
    {
        int temp = H[i];
        H[i] = H[i/2];
        H[i/2] = temp;

        display(H,n);

        i = i/2;
    }
}

int main()
{
    int H[100] = {0, 5, 7, 19, 17, 42, 34, 20, 40};
    int n = 8;

    cout << "Initial Heap: ";
    display(H,n);

    cout << "\nInserting 6:\n";
    insert(H,n,6);

    cout << "\nInserting 4:\n";
    insert(H,n,4);

    cout << "\nHeap after insertions: ";
    display(H,n);

    cout << "\nFirst ExtractMin: ";
    cout << extractMin(H,n) << endl;

    cout << "\nSecond ExtractMin: ";
    cout << extractMin(H,n) << endl;

    cout << "\nHeap after extractions: ";
    display(H,n);

    cout << "\nDecreaseKey at index 7 (20 to 3):\n";
    decreaseKey(H,n,7,3);

    cout << "\nFinal Heap: ";
    display(H,n);

    return 0;
}
