#include <iostream>
using namespace std;

struct node
{
    int vertex, weight;
    node *next;
} *head[20];

int n, visit[20], dist[20], pre[20];

void addEdge(int u, int v, int w)
{
    node *temp = new node;
    temp->vertex = v; // FIXED
    temp->weight = w;
    temp->next = head[u];
    head[u] = temp;
}

void prim(int start)
{

    for (int i = 1; i <= n; i++)
    {
        visit[i] = 0;
        dist[i] = 9999;
        pre[i] = -1;
    }

    dist[start] = 0;

    for (int k = 1; k <= n; k++)
    {

        int u = -1;
        int minDist = 9999;

        // pick unvisited vertex with minimum dist
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        visit[u] = 1;

        // update neighbours
        node *p = head[u];
        while (p != NULL)
        {
            int v = p->vertex;
            int w = p->weight;

            if (!visit[v] && w < dist[v])
            {
                dist[v] = w;
                pre[v] = u;
            }
            p = p->next;
        }
    }

    // Print MST
    int cost = 0;
    cout << "\nMST Edges:\n";
    for (int i = 1; i <= n; i++)
    {
        if (pre[i] != -1)
        {
            cout << pre[i] << " -> " << i << " (weight " << dist[i] << ")\n";
            cost += dist[i];
        }
    }
    cout << "Total Minimum Cost = " << cost << endl;
}

int main()
{

    int e, u, v, w;

    cout << "Enter total edges: ";
    cin >> e;
    cout << "Enter total vertices: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
        head[i] = NULL;

    for (int i = 1; i <= e; i++)
    {
        cout << "Enter (u v w): ";
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w); // undirected
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    prim(start);
}
