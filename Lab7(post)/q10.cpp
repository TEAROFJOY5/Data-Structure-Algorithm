/*
Task 10: Sorting Showdown and Smart Selector
Part A: Benchmark
Build one test program that runs Quick Sort, Merge Sort and Radix Sort on the same copy of the data. Add counters for comparisons and element writes / moves (for Radix Sort, count digit extractions and writes into output; its comparisons will be zero).
Generate the following datasets, each of size 20, 200 and 2000:
already sorted
reverse sorted
random with values up to 99
random with values up to 999999
many duplicates (only 3 different values)
Fill a table with the counters for every combination. For the largest sorted input also record the maximum recursion depth of Quick Sort (with right-most pivot). What happens to the program when the sorted size is made very large, for example 100000, and why (mention in comments)?
Part B: Smart Selector
Write a function smartSort(arr, n) that inspects the input first (for example: size, the maximum value, whether it is already sorted, whether it has negative values) and then chooses which of the three algorithms to call. Print which algorithm was chosen and the reason. It is acceptable to use the middle-pivot version from Task 5 and the negative handling from Task 8. Run smartSort on at least 5 different inputs of your own design and justify each choice using your benchmark table.

 */

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Counter
{
    long long comparisons;
    long long writes;
    long long digits;
    int maxDepth;

    Counter()
    {
        comparisons=0;
        writes=0;
        digits=0;
        maxDepth=0;
    }
};

void swapValues(int &a, int &b, Counter &c)
{
    if(&a != &b)
    {
        int temp=a;
        a=b;
        b=temp;
        c.writes+=2;
    }
}

int partition(int *arr, int lb, int ub, Counter &c, int depth)
{
    if(depth>c.maxDepth)
        c.maxDepth=depth;

    int pivot=arr[ub];
    int i=lb-1;

    for(int j=lb; j<ub; j++)
    {
        c.comparisons++;

        if(arr[j]<=pivot)
        {
            i++;
            swapValues(arr[i],arr[j],c);
        }
    }

    if(i+1!=ub)
    {
        swapValues(arr[i+1],arr[ub],c);
    }

    return i+1;
}

void quickSort(int *arr, int lb, int ub, Counter &c, int depth=1)
{
    if(lb<ub)
    {
        if(depth>c.maxDepth)
            c.maxDepth=depth;

        int p=partition(arr,lb,ub,c,depth);
        quickSort(arr,lb,p-1,c,depth+1);
        quickSort(arr,p+1,ub,c,depth+1);
    }
    else if(lb==ub && depth>c.maxDepth)
        c.maxDepth=depth;
}

void merge(int *arr, int lb, int mid, int ub, Counter &c)
{
    int *temp=new int[ub-lb+1];
    int i=lb, j=mid+1, k=0;

    while(i<=mid && j<=ub)
    {
        c.comparisons++;

        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];

        c.writes++;
    }

    while(i<=mid)
    {
        temp[k++]=arr[i++];
        c.writes++;
    }

    while(j<=ub)
    {
        temp[k++]=arr[j++];
        c.writes++;
    }

    for(i=lb,k=0; i<=ub; i++,k++)
    {
        arr[i]=temp[k];
        c.writes++;
    }

    delete[] temp;
}

void mergeSort(int *arr, int lb, int ub, Counter &c)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergeSort(arr,lb,mid,c);
        mergeSort(arr,mid+1,ub,c);
        merge(arr,lb,mid,ub,c);
    }
}

void radixNonNegative(int *arr, int n, Counter &c)
{
    if(n<=1)
        return;

    int maxValue=arr[0];

    for(int i=1; i<n; i++)
        if(arr[i]>maxValue)
            maxValue=arr[i];

    int *output=new int[n];

    for(long long exp=1; maxValue/exp>0; exp*=10)
    {
        int count[10]={0};

        for(int i=0; i<n; i++)
        {
            int digit=(arr[i]/exp)%10;
            c.digits++;
            count[digit]++;
        }

        for(int i=1; i<10; i++)
            count[i]+=count[i-1];

        for(int i=n-1; i>=0; i--)
        {
            int digit=(arr[i]/exp)%10;
            c.digits++;
            output[--count[digit]]=arr[i];
            c.writes++;
        }

        for(int i=0; i<n; i++)
        {
            arr[i]=output[i];
            c.writes++;
        }
    }

    delete[] output;
}

void radixSort(int *arr, int n, Counter &c)
{
    int *negative=new int[n];
    int *positive=new int[n];
    int negCount=0, posCount=0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]<0)
            negative[negCount++]=-arr[i];
        else
            positive[posCount++]=arr[i];
    }

    radixNonNegative(negative,negCount,c);
    radixNonNegative(positive,posCount,c);

    int k=0;

    for(int i=negCount-1; i>=0; i--)
    {
        arr[k++]=-negative[i];
        c.writes++;
    }

    for(int i=0; i<posCount; i++)
    {
        arr[k++]=positive[i];
        c.writes++;
    }

    delete[] negative;
    delete[] positive;
}

void copyArray(int *source, int *dest, int n)
{
    for(int i=0; i<n; i++)
        dest[i]=source[i];
}

void makeData(int *arr, int n, int type)
{
    if(type==0)
    {
        for(int i=0; i<n; i++)
            arr[i]=i;
    }
    else if(type==1)
    {
        for(int i=0; i<n; i++)
            arr[i]=n-i;
    }
    else if(type==2)
    {
        for(int i=0; i<n; i++)
            arr[i]=rand()%100;
    }
    else if(type==3)
    {
        for(int i=0; i<n; i++)
            arr[i]=rand()%1000000;
    }
    else
    {
        for(int i=0; i<n; i++)
            arr[i]=rand()%3;
    }
}

void benchmark(int *original, int n, const char *name)
{
    int *a=new int[n];
    int *b=new int[n];
    int *d=new int[n];

    Counter q,m,r;

    copyArray(original,a,n);
    copyArray(original,b,n);
    copyArray(original,d,n);

    quickSort(a,0,n-1,q);
    mergeSort(b,0,n-1,m);
    radixSort(d,n,r);

    cout<<name<<" ("<<n<<")\n";
    cout<<"Quick Sort: Comparisons="<<q.comparisons
        <<", Writes="<<q.writes;

    if(n==2000 && name[0]=='A')
        cout<<", Max Depth="<<q.maxDepth;

    cout<<"\nMerge Sort: Comparisons="<<m.comparisons
        <<", Writes="<<m.writes;
    cout<<"\nRadix Sort: Comparisons="<<r.comparisons
        <<", Digit Extractions="<<r.digits
        <<", Writes="<<r.writes<<"\n\n";

    delete[] a;
    delete[] b;
    delete[] d;
}

bool isSorted(int *arr, int n)
{
    for(int i=1; i<n; i++)
        if(arr[i]<arr[i-1])
            return false;

    return true;
}

bool hasNegative(int *arr, int n)
{
    for(int i=0; i<n; i++)
        if(arr[i]<0)
            return true;

    return false;
}

int maximumValue(int *arr, int n)
{
    int maximum=0;

    for(int i=0; i<n; i++)
    {
        int value=arr[i];

        if(value<0)
            value=-value;

        if(value>maximum)
            maximum=value;
    }

    return maximum;
}

void quickSortMiddle(int *arr, int lb, int ub)
{
    int i=lb, j=ub;
    int pivot=arr[(lb+ub)/2];

    while(i<=j)
    {
        while(arr[i]<pivot)
            i++;

        while(arr[j]>pivot)
            j--;

        if(i<=j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }

    if(lb<j)
        quickSortMiddle(arr,lb,j);

    if(i<ub)
        quickSortMiddle(arr,i,ub);
}

void smartSort(int *arr, int n)
{
    if(n<=1)
    {
        cout<<"No sorting needed: size is 0 or 1.\n";
        return;
    }

    bool sorted=isSorted(arr,n);
    bool negative=hasNegative(arr,n);
    int maximum=maximumValue(arr,n);

    if(sorted)
    {
        cout<<"Merge Sort selected: input is already sorted; "
            <<"Merge Sort also avoids bad Quick Sort partitions.\n";
        Counter c;
        mergeSort(arr,0,n-1,c);
    }
    else if(negative)
    {
        cout<<"Radix Sort selected: negative values are handled "
            <<"by separating negative and nonnegative values.\n";
        Counter c;
        radixSort(arr,n,c);
    }
    else if(maximum>=100000)
    {
        cout<<"Radix Sort selected: large numeric range; "
            <<"digit-based sorting avoids comparison sorting.\n";
        Counter c;
        radixSort(arr,n,c);
    }
    else if(n<=20)
    {
        cout<<"Quick Sort selected: small input; middle pivot "
            <<"helps avoid the right-pivot worst case.\n";
        quickSortMiddle(arr,0,n-1);
    }
    else
    {
        cout<<"Merge Sort selected: larger input; predictable "
            <<"O(n log n) time and no deep Quick Sort recursion.\n";
        Counter c;
        mergeSort(arr,0,n-1,c);
    }

    cout<<"Sorted: ";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n\n";
}

int main()
{
    srand(10);

    int sizes[]={20,200,2000};
    const char *names[]={
        "A. Already sorted",
        "B. Reverse sorted",
        "C. Random 0-99",
        "D. Random 0-999999",
        "E. Three different values"
    };

    for(int type=0; type<5; type++)
    {
        for(int s=0; s<3; s++)
        {
            int n=sizes[s];
            int *arr=new int[n];

            makeData(arr,n,type);
            benchmark(arr,n,names[type]);

            delete[] arr;
        }
    }

    cout<<"SMART SELECTOR TESTS\n\n";

    int a[]={1,2,3,4,5,6};
    int b[]={9,8,7,6,5,4};
    int c[]={-45,170,-5,24,-2,0};
    int d[]={900000,12,450000,5,800000};
    int e[]={8,2,5,1,9,3,4,7,6,0};
    int f[]={2,1,2,1,2,1,2,1,2,1};

    smartSort(a,6);
    smartSort(b,6);
    smartSort(c,6);
    smartSort(d,5);
    smartSort(e,10);
    smartSort(f,10);

    // A sorted array of size 100000 can cause very deep recursion
    // with right-most-pivot Quick Sort, potentially overflowing the
    // call stack. Do not run that test with this recursive version.

    return 0;
}
