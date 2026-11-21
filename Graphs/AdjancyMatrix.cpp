
#include <iostream>
using namespace std;

#define MAX 10

int main()
{
    int graph[MAX][MAX];
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    // Initialize matrix with 0
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Take edges from user
    for(int i = 0; i < edges; i++)
    {
        int u, v;

        cout << "Enter edge (u v): ";
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";

    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
