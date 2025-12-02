#include <iostream>
using namespace std;
struct node
{
    int v, w;
    node *next;
} *head[20];

int visited[20], dist[20], parent[20];
int n;

void addEdge(int u, int v, int w)
{
    node *temp = new node;
    temp->v = v;
    temp->w = w;
    temp->next = head[u];
    head[u] = temp;
}

void prim(int start)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 32767;
        visited[i] = 0;
        parent[i] = 0;
    }
    dist[start] = 0;
    
    for (int c = 1; c <= n; c++)
    {
        int u = 0, min = 32767;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        visited[u] = 1;
        node *p = head[u];
        while (p != NULL)
        {
            if (!visited[p->v] && dist[p->v] > p->w)
            {
                dist[p->v] = p->w;
                parent[p->v] = u;
            }
            p = p->next;
        }
    }

    int cost = 0;
    cout << "\nEdges in MST:\n";
    for (int i = 1; i <= n; i++)
    {
        cost += dist[i];
        if (parent[i] != 0)
            cout << parent[i] << " -> " << i << " ( " << dist[i] << " )\n";
    }

    cout << "\nMinimum Cost = " << cost;
}

void main()
{
    int e, u, v, w;

    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 1; i <= n; i++)
        head[i] = NULL;

    for (int i = 1; i <= e; i++)
    {
        cout << "Enter edge (u v w): ";
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    cout << "Enter start vertex: ";
    cin >> u;
    prim(u);
}
