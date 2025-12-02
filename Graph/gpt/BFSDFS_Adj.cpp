#include <iostream>
using namespace std;
int adj[20][20], visited[20], q[20], front = -1, rear = -1;
int n;

void bfs(int start)
{
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    front = rear = -1;
    visited[start] = 1;
    q[++rear] = start;

    cout << "\nBFS Traversal: ";

    while (front != rear)
    {
        int u = q[++front];
        cout << u << " ";

        for (int v = 1; v <= n; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q[++rear] = v;
            }
        }
    }
}

void dfs(int start)
{
    visited[start] = 1;
    cout << start << " ";
    for (int v = 1; v <= n; v++)
    {
        if (adj[start][v] == 1 && visited[v] == 0)
            dfs(v);
    }
}

void main()
{
    int edges, u, v;

    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> edges;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    for (int i = 1; i <= edges; i++)
    {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    cout << "\nEnter start vertex for BFS: ";
    cin >> u;                       
    bfs(u);
    
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    cout << "\nDFS Traversal: ";
    cout << "\nEnter start vertex for DFS: ";
    cin >> v;
    dfs(v);
}
