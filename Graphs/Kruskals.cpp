
#include <iostream>
using namespace std;

#define V 5
#define E 10

struct Edge
{
    int src;
    int dest;
    int weight;
};

int find(int parent[], int i)
{
    while(parent[i] != i)
    {
        i = parent[i];
    }

    return i;
}

void Union(int parent[], int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    parent[rootX] = rootY;
}

void kruskal(int graph[V][V])
{
    Edge edges[E];
    int count = 0;

    // Store all edges
    for(int i = 0; i < V; i++)
    {
        for(int j = i + 1; j < V; j++)
        {
            if(graph[i][j] != 0)
            {
                edges[count].src = i;
                edges[count].dest = j;
                edges[count].weight = graph[i][j];
                count++;
            }
        }
    }

    // Bubble sort edges by weight
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent array
    int parent[V];

    for(int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int total = 0;
    int selected = 0;

    cout << "Edge \tWeight\n";

    // Select edges
    for(int i = 0; i < count && selected < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        int rootU = find(parent, u);
        int rootV = find(parent, v);

        if(rootU != rootV)
        {
            cout << u << " - " << v
                 << "\t" << edges[i].weight << endl;

            total += edges[i].weight;

            Union(parent, rootU, rootV);

            selected++;
        }
    }

    if(selected != V - 1)
    {
        cout << "MST does not exist";
        return;
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

    kruskal(graph);

    return 0;
}
