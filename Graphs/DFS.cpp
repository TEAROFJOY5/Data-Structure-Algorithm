
#include <iostream>
using namespace std;

#define V 5

void DFS(int graph[V][V], int start)
{
    int visited[V] = {0};

    int stack[V];
    int top = -1;

    // Push starting vertex
    stack[++top] = start;
    visited[start] = 1;

    while(top != -1)
    {
        int current = stack[top--];

        cout << current << " ";

        // Check adjacent vertices
        for(int i = V - 1; i >= 0; i--)
        {
            if(graph[current][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
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

    cout << "DFS Traversal: ";

    DFS(graph, 0);

    return 0;
}

