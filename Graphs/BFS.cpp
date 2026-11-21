
#include <iostream>
using namespace std;

#define V 5

void BFS(int graph[V][V], int start)
{
    int visited[V] = {0};

    int queue[V];
    int front = 0;
    int rear = -1;

    // Insert starting vertex
    queue[++rear] = start;
    visited[start] = 1;

    while(front <= rear)
    {
        int current = queue[front++];

        cout << current << " ";

        // Check adjacent vertices
        for(int i = 0; i < V; i++)
        {
            if(graph[current][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
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

    cout << "BFS Traversal: ";

    BFS(graph, 0);

    return 0;
}
