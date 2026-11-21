// Using Adjancy Matrix.

#include <iostream>
using namespace std;

#define V 5

void DFS(int graph[V][V], int visited[], int vertex)
{
    // Visit current vertex
    cout << vertex << " ";
    visited[vertex] = 1;

    // Check all adjacent vertices
    for(int i = 0; i < V; i++)
    {
        if(graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(graph, visited, i);
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

    int visited[V] = {0};

    cout << "DFS Traversal: ";

    DFS(graph, visited, 0);

    return 0;
}
