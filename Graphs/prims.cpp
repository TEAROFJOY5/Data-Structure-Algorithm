
#include <iostream>
using namespace std;

#define V 5
#define INF 99999

void prim(int graph[V][V])
{
    int parent[V];
    int key[V];
    int visited[V];

    for(int i = 0; i < V; i++)
    {
        key[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;

    for(int count = 0; count < V - 1; count++)
    {
        int min = INF;
        int u = -1;

        for(int i = 0; i < V; i++)
        {
            if(visited[i] == 0 && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        if(u == -1)
            return;

        visited[u] = 1;

        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] != 0 &&
               visited[v] == 0 &&
               graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;

    cout << "Edge \tWeight\n";

    for(int i = 1; i < V; i++)
    {
        if(parent[i] == -1)
        {
            cout << "MST does not exist\n";
            return;
        }

        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "Total MST Weight: " << total;
}

int main()
{
    int graph[V][V] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(graph);

    return 0;
}
