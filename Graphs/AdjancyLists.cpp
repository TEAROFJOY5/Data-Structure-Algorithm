
#include <iostream>
using namespace std;

#define MAX 10

struct Node
{
    int vertex;
    Node* next;
};

int main()
{
    Node* head[MAX];

    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    // Initialize head pointers
    for(int i = 0; i < vertices; i++)
    {
        head[i] = NULL;
    }

    // Take edges from user
    for(int i = 0; i < edges; i++)
    {
        int u, v;

        cout << "Enter edge (u v): ";
        cin >> u >> v;

        // Create node for v in u's list
        Node* newNode = new Node;

        newNode->vertex = v;
        newNode->next = head[u];
        head[u] = newNode;

        // Create node for u in v's list
        newNode = new Node;

        newNode->vertex = u;
        newNode->next = head[v];
        head[v] = newNode;
    }

    // Display adjacency list
    cout << "\nAdjacency List:\n";

    for(int i = 0; i < vertices; i++)
    {
        cout << i << " -> ";

        Node* temp = head[i];

        while(temp != NULL)
        {
            cout << temp->vertex << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Free allocated memory
    for(int i = 0; i < vertices; i++)
    {
        Node* temp = head[i];

        while(temp != NULL)
        {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
    }

    return 0;
}
