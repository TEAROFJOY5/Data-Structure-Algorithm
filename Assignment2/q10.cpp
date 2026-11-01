
#include<iostream>
using namespace std;

int count = 0;

void findCombinations(int digits[], int total, int N, int S,
                      int result[], int index, int start, int sum)
{
    if(index == N)
    {
        if(sum == S)
        {
            count++;

            for(int i=0; i<N; i++)
                cout<<result[i]<<" ";

            cout<<endl;
        }

        return;
    }

    for(int i=start; i<total; i++)
    {
        if(sum + digits[i] <= S)
        {
            result[index] = digits[i];

            findCombinations(digits, total, N, S,
                             result, index+1, i+1,
                             sum + digits[i]);
        }
    }
}

int main()
{
    int digits[] = {1, 2, 3, 4, 5};

    int total = 5;
    int N = 3;
    int S = 9;

    int result[10];

    findCombinations(digits, total, N, S,
                     result, 0, 0, 0);

    if(count == 0)
        cout<<"No valid combination exists."<<endl;
    else
        cout<<"\nTotal combinations: "<<count<<endl;

    return 0;
}
