#include<iostream>
using namespace std;

int mergeCalls = 0;

struct Student
{
    char id[10];
    char name[30];
    char department[20];
    float cgpa;
};

void merge(Student* arr, int lb, int mid, int ub, int depth);

void MergeSort(Student* arr, int lb, int ub, int depth)
{
    if(lb < ub)
    {
        for(int i=0; i<depth; i++)
            cout<<"  ";

        cout<<"Split ["<<lb<<".."<<ub<<"]"<<endl;

        int mid = (lb+ub)/2;

        MergeSort(arr, lb, mid, depth+1);
        MergeSort(arr, mid+1, ub, depth+1);

        merge(arr, lb, mid, ub, depth);
    }
}

void merge(Student* arr, int lb, int mid, int ub, int depth)
{
    mergeCalls++;

    Student* b = new Student[ub-lb+1];

    int i = lb;
    int j = mid+1;
    int k = 0;

    while(i<=mid && j<=ub)
    {
        if(arr[i].cgpa >= arr[j].cgpa)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    while(j<=ub)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    for(i=lb, k=0; i<=ub; i++, k++)
        arr[i] = b[k];

    for(int i=0; i<depth; i++)
        cout<<"  ";

    cout<<"Merge ["<<lb<<".."<<ub<<"] -> ";

    for(int i=lb; i<=ub; i++)
        cout<<arr[i].cgpa<<" ";

    cout<<endl;

    delete[] b;
}

const char* getAward(float cgpa)
{
    if(cgpa >= 4.00)
        return "Rector's List";
    else if(cgpa >= 3.50)
        return "Dean's List";

    return "No Award";
}

int main()
{
    Student students[30] =
    {
        {"S001","Ali","CS",3.80},
        {"S002","Sara","SE",4.00},
        {"S003","Ahmed","AI",3.50},
        {"S004","Hina","CS",3.90},
        {"S005","Bilal","DS",3.70},
        {"S006","Ayesha","SE",3.99},
        {"S007","Usman","CS",3.50},
        {"S008","Zain","AI",3.20},
        {"S009","Fatima","DS",4.00},
        {"S010","Hamza","SE",3.80},
        {"S011","Noor","CS",3.60},
        {"S012","Omar","AI",3.99},
        {"S013","Maryam","DS",3.40},
        {"S014","Hassan","SE",3.70},
        {"S015","Iqra","CS",3.90},
        {"S016","Daniyal","AI",3.30},
        {"S017","Laiba","DS",3.60},
        {"S018","Huzaifa","SE",4.00},
        {"S019","Anaya","CS",3.50},
        {"S020","Saad","AI",3.85},
        {"S021","Maham","DS",3.75},
        {"S022","Taha","SE",3.20},
        {"S023","Eman","CS",3.99},
        {"S024","Raza","AI",3.45},
        {"S025","Zoya","DS",3.70},
        {"S026","Farhan","SE",3.90},
        {"S027","Muneeb","CS",3.55},
        {"S028","Hoorain","AI",3.85},
        {"S029","Arham","DS",3.00},
        {"S030","Nimra","SE",3.60}
    };

    int n = 30;

    cout<<"MERGE SORT PROCESS"<<endl<<endl;

    MergeSort(students, 0, n-1, 0);

    cout<<"\nTotal Merge Calls: "<<mergeCalls<<endl;

    cout<<"\nFINAL MERIT LIST\n\n";

    cout<<"Rank\tID\tName\t\tDepartment\tCGPA\tAward"<<endl;

    int rank = 1;

    for(int i=0; i<n; i++)
    {
        if(i > 0 && students[i].cgpa != students[i-1].cgpa)
            rank = i+1;

        cout<<rank<<"\t"
            <<students[i].id<<"\t"
            <<students[i].name<<"\t\t"
            <<students[i].department<<"\t\t"
            <<students[i].cgpa<<"\t"
            <<getAward(students[i].cgpa)
            <<endl;
    }

    return 0;
}
