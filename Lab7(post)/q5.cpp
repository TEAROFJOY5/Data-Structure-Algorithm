/*
Task 5: A teacher has the following student records (name, marks), stored in this order:
(Ali, 70), (Sara, 85), (Bilal, 70), (Aina, 85), (Omar, 70)
Change the three algorithms so they sort an array of this struct by marks only. Radix Sort will need the marks as the key, and elements must move as whole records.
Print the result of each algorithm. For each, check: do students with equal marks still appear in their original relative order?
Break Merge Sort on purpose: change <= to < in the merge condition. Run again. What changes and why?
Break Radix Sort on purpose: in countingSort, change the "Build output" loop to go from 0 to n - 1 instead of n - 1 down to 0. Test on {170, 45, 75, 90, 802, 24, 2, 66} and on {21, 11, 22, 12} and mention in comment what went wrong. Why does the correctness of the next pass depend on this?
Which of the three algorithms is not stable in the given form? Show the exact swap in your trace that proves it

*/

#include<iostream>
using namespace std;

struct Student
{
    string name;
    int marks;
};

void swap(Student &a, Student &b)
{
    Student temp = a;
    a = b;
    b = temp;
}

void display(Student *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<"("<<arr[i].name<<", "<<arr[i].marks<<") ";
    }
    cout<<endl;
}

void shellSort(Student *arr, int size)
{
    int gap;

    for(gap=size/2; gap>=1; gap=gap/2)
    {
        for(int j=gap; j<size; j++)
        {
            for(int i=j-gap; i>=0; i-=gap)
            {
                if(arr[i+gap].marks>=arr[i].marks)
                    break;
                else
                    swap(arr[i+gap], arr[i]);
            }
        }
    }
}

void merge(Student *arr, int lb, int mid, int ub, bool broken)
{
    Student *b = new Student[ub-lb+1];

    int i=lb;
    int j=mid+1;
    int k=0;

    while(i<=mid && j<=ub)
    {
        if(broken ? arr[i].marks<arr[j].marks :
                    arr[i].marks<=arr[j].marks)
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid)
    {
        b[k]=arr[i];
        i++;
        k++;
    }

    while(j<=ub)
    {
        b[k]=arr[j];
        j++;
        k++;
    }

    for(i=lb, k=0; i<=ub; i++, k++)
        arr[i]=b[k];

    delete[] b;
}

void mergeSort(Student *arr, int lb, int ub, bool broken)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;

        mergeSort(arr, lb, mid, broken);
        mergeSort(arr, mid+1, ub, broken);
        merge(arr, lb, mid, ub, broken);
    }
}

void countingSort(Student *arr, int size, int place, bool broken)
{
    Student *output = new Student[size];
    int count[10]={0};

    for(int i=0; i<size; i++)
        count[(arr[i].marks/place)%10]++;

    for(int i=1; i<10; i++)
        count[i]=count[i]+count[i-1];

    if(broken)
    {
        for(int i=0; i<size; i++)
        {
            int digit=(arr[i].marks/place)%10;
            output[count[digit]-1]=arr[i];
            count[digit]--;
        }
    }
    else
    {
        for(int i=size-1; i>=0; i--)
        {
            int digit=(arr[i].marks/place)%10;
            output[count[digit]-1]=arr[i];
            count[digit]--;
        }
    }

    for(int i=0; i<size; i++)
        arr[i]=output[i];

    delete[] output;
}

void radixSort(Student *arr, int size, bool broken)
{
    int max=arr[0].marks;

    for(int i=1; i<size; i++)
    {
        if(arr[i].marks>max)
            max=arr[i].marks;
    }

    for(int place=1; max/place>0; place*=10)
        countingSort(arr, size, place, broken);
}

int main()
{
    Student arr1[]={{"Ali",70},{"Sara",85},{"Bilal",70},
                    {"Aina",85},{"Omar",70}};

    Student arr2[]={{"Ali",70},{"Sara",85},{"Bilal",70},
                    {"Aina",85},{"Omar",70}};

    Student arr3[]={{"Ali",70},{"Sara",85},{"Bilal",70},
                    {"Aina",85},{"Omar",70}};

    int size=5;

    cout<<"Shell Sort:"<<endl;
    shellSort(arr1, size);
    display(arr1, size);

    cout<<"\nMerge Sort:"<<endl;
    mergeSort(arr2, 0, size-1, false);
    display(arr2, size);

    cout<<"\nBroken Merge Sort:"<<endl;
    mergeSort(arr3, 0, size-1, true);
    display(arr3, size);

    Student arr4[]={{"Ali",70},{"Sara",85},{"Bilal",70},
                    {"Aina",85},{"Omar",70}};

    cout<<"\nRadix Sort:"<<endl;
    radixSort(arr4, size, false);
    display(arr4, size);

    Student arr5[]={{"Ali",70},{"Sara",85},{"Bilal",70},
                    {"Aina",85},{"Omar",70}};

    cout<<"\nBroken Radix Sort:"<<endl;
    radixSort(arr5, size, true);
    display(arr5, size);

    Student arr6[]={{"A",170},{"B",45},{"C",75},{"D",90},
                    {"E",802},{"F",24},{"G",2},{"H",66}};

    cout<<"\nBroken Radix Sort Test 1:"<<endl;
    radixSort(arr6, 8, true);
    display(arr6, 8);

    Student arr7[]={{"A",21},{"B",11},{"C",22},{"D",12}};

    cout<<"\nBroken Radix Sort Test 2:"<<endl;
    radixSort(arr7, 4, true);
    display(arr7, 4);
}
