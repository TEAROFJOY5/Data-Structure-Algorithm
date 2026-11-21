
#include <iostream>
using namespace std;

#define V 5

void DFS(int graph[V][V], int start)
{
    int visited[V] = {0};

    int stack[V];
    int next[V];
    int top = -1;

    stack[++top] = start;
    next[top] = 0;
    visited[start] = 1;

    while(top != -1)
    {
        int current = stack[top];

        if(next[top] < V)
        {
            int neighbor = next[top]++;

            if(graph[current][neighbor] == 1 &&
               visited[neighbor] == 0)
            {
                visited[neighbor] = 1;

                stack[++top] = neighbor;
                next[top] = 0;
            }
        }
        else
        {
            top--;
        }
    }
}

int main()
{
    int graph[V][V] =
    {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    DFS(graph, 0);

    return 0;
}
