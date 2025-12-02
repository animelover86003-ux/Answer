#include <iostream>
#include <queue>
using namespace std;
int adj[20][20], n, visited[20], u, v;

void bfs(int start)
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    queue<int> q;
    visited[start] = 1;

    q.push(start);

    cout << "Traversing BFS........." << endl;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v = 1; v <= n; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

void dfs(int start){
    visited[start] = 1;
    cout<<start<<" ";
    for (int v=1; v <= n; v++)
    {
        if (adj[start][v]==1&&visited[v]==0)
        {
            dfs(v);
        }
    }
}

int main()
{
    int edge, vertices;
    cout << "Enter Edges : ";
    cin >> edge;
    cout << "Enter vertices :";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (int j = 1; j <= edge; j++)
    {
        cout << "Enter edge (u v) " << j << " : ";
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    int value;
    cout << "Enter Start Vertex for bfs : ";
    cin >> value;
    bfs(value);
    
    for (int i = 1; i <=n; i++)
    {
        visited[i]=0;
    }
    
    cout<<"\nEnter Start For Vertex DFS :";
    cin>>value;
    cout << "Traversing DFS........." << endl;

    dfs(value);
    
    
    return 0;
}