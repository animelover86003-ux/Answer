#include <iostream>
#include <queue>
using namespace std;

int adj[20][20], u, v, n, visited[20];

void bfs(int s_value)
{
    queue<int> q;
    visited[s_value] = 1;
    q.push(s_value);
    cout << "BFS Travelsing....." << endl;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << "-";
        for (int v = 1; v <= n; v++)
        {
            if (visited[v] == 0 && adj[u][v] == 1)
            {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

void dfs(int s_value)
{
    visited[s_value] = 1;
    cout << s_value << "-";
    for (int v = 1; v <= n; v++)
    {
        if (adj[s_value][v] == 1 && visited[v] == 0)
        {
            dfs(v);
        }
    }
}

int main()
{
    adj[20][20] = {0};
    visited[20] = {0};
    int edge, start_value;
    cout << "Enter The No of Edges : ";
    cin >> edge;
    cout << "Enter The No of Vertices : ";
    cin >> n;

    for (int i = 1; i <= edge; i++)
    {
        cout << "Enter Edge Vertices (u v) :";
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    cout << "Enter Value For BFS :";
    cin >> start_value;
    bfs(start_value);

    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    cout << "\nEnter Value For DFS :";
    cin >> start_value;
    dfs(start_value);
}