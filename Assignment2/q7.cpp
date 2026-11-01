#include<iostream>
using namespace std;

struct Parcel
{
    int trackingNo;
    char sender[50];
    char city[30];
    int regionCode;
};

int getDigit(int num, int exp)
{
    return (num/exp)%10;
}

void radixSort(Parcel* arr, int lb, int ub, int exp)
{
    if(lb >= ub || exp == 0)
        return;

    int count[10] = {0};
    int start[10];
    int next[10];
    int end[10];

    for(int i=lb; i<=ub; i++)
    {
        int digit = getDigit(arr[i].trackingNo, exp);
        count[digit]++;
    }

    start[0] = lb;

    for(int i=1; i<10; i++)
        start[i] = start[i-1] + count[i-1];

    for(int i=0; i<10; i++)
    {
        next[i] = start[i];
        end[i] = start[i] + count[i];
    }

    for(int i=0; i<10; i++)
    {
        while(next[i] < end[i])
        {
            int digit = getDigit(arr[next[i]].trackingNo, exp);

            if(digit == i)
            {
                next[i]++;
            }
            else
            {
                int pos = next[digit];

                Parcel temp = arr[next[i]];
                arr[next[i]] = arr[pos];
                arr[pos] = temp;

                next[digit]++;
            }
        }
    }

    if(exp > 1)
    {
        for(int i=0; i<10; i++)
        {
            if(count[i] > 1)
                radixSort(arr, start[i], end[i]-1, exp/10);
        }
    }
}

int main()
{
    Parcel parcels[] =
    {
        {170,"Ali","Karachi",2},
        {45,"Turab","Quettao",1},
        {75,"Ahmed","Quetta",3},
        {90,"Abdullah","kandahar",2},
        {802,"Bilal","Karachi",1},
        {24,"Zeshan","Peshawar",3},
        {2,"Usman","Lahore",2},
        {66,"Fatima","Quetta",1},
        {1000,"Omar","Karachi",3},
        {7,"Noor","Islamabad",2}
    };

    int n = sizeof(parcels)/sizeof(parcels[0]);

    radixSort(parcels, 0, n-1, 100000000);

    cout<<"SORTED PARCELS\n\n";

    for(int i=0; i<n; i++)
    {
        cout<<parcels[i].trackingNo<<"\t"
            <<parcels[i].sender<<"\t"
            <<parcels[i].city<<"\t"
            <<parcels[i].regionCode<<endl;
    }

    return 0;
}
