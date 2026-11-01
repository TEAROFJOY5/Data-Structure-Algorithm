
#include<iostream>
using namespace std;

struct Job
{
    int jobNo;
    int priority;
    int arrival;
};

class PriorityQueue
{
    Job H[100];
    int size;
    int arrivalNo;

    bool smaller(Job a, Job b)
    {
        if(a.priority < b.priority)
            return true;

        if(a.priority == b.priority && a.arrival < b.arrival)
            return true;

        return false;
    }

    void heapifyUp(int i)
    {
        while(i > 1 && smaller(H[i], H[i/2]))
        {
            Job temp = H[i];
            H[i] = H[i/2];
            H[i/2] = temp;

            i = i/2;
        }
    }

    void heapifyDown(int i)
    {
        while(2*i <= size)
        {
            int small = 2*i;

            if(2*i+1 <= size && smaller(H[2*i+1], H[2*i]))
                small = 2*i+1;

            if(!smaller(H[small], H[i]))
                break;

            Job temp = H[i];
            H[i] = H[small];
            H[small] = temp;

            i = small;
        }
    }

public:

    PriorityQueue()
    {
        size = 0;
        arrivalNo = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(int job, int priority)
    {
        if(size == 99)
            return;

        size++;
        arrivalNo++;

        H[size].jobNo = job;
        H[size].priority = priority;
        H[size].arrival = arrivalNo;

        heapifyUp(size);
    }

    Job pop()
    {
        Job temp;

        temp.jobNo = -1;
        temp.priority = -1;
        temp.arrival = -1;

        if(size == 0)
            return temp;

        Job min = H[1];

        H[1] = H[size];
        size--;

        if(size > 0)
            heapifyDown(1);

        return min;
    }

    Job peek()
    {
        Job temp;

        temp.jobNo = -1;
        temp.priority = -1;
        temp.arrival = -1;

        if(size == 0)
            return temp;

        return H[1];
    }
};

int main()
{
    PriorityQueue pq;
    Job temp;

    pq.push(1,2);
    pq.push(2,1);
    pq.push(3,2);

    temp = pq.pop();
    cout << "POP: J" << temp.jobNo << endl;

    pq.push(4,1);
    pq.push(5,3);

    temp = pq.pop();
    cout << "POP: J" << temp.jobNo << endl;

    temp = pq.pop();
    cout << "POP: J" << temp.jobNo << endl;

    pq.push(6,1);

    while(!pq.isEmpty())
    {
        temp = pq.pop();
        cout << "POP: J" << temp.jobNo << endl;
    }

    return 0;
}
