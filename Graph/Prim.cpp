#include <iostream>
using namespace std;

int visited[20], dist[20], pre[20], weight[20][20];
int n, u, v, w, edge;

void prim()
{
    int current = 1;
    int total = 1;
    int minCost, i;
 
    visited[current] = 1;
    dist[current] = 0;

    while (total != n)
    {
        // update neighbors
        for (int i = 1; i <= n; i++)
        {
            if (weight[current][i] != 0 && visited[i] == 0)
            {
                if (dist[i] > weight[current][i])
                {
                    dist[i] = weight[current][i];
                    pre[i] = current;
                }
            }
        }

        // find next min
        minCost = 9999;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && dist[i] < minCost)
            {
                minCost = dist[i];
                current = i;
            }
        }

        visited[current] = 1;
        total++;
    }

    // print cost
    minCost = 0;
    for (int i = 1; i <= n; i++)
        minCost += dist[i];

    cout << "\nMinimum Cost : " << minCost;

    // print MST
    cout << "\nMinimum Spanning Tree:";
    for (int i = 1; i <= n; i++)
        cout << "\nVertex " << i << " is connected to " << pre[i];
}

int main()
{
    cout << "Enter The No of edges : ";
    cin >> edge;
    cout << "Enter The No of Vertices : ";
    cin >> n;

    // initialize arrays
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 9999;
        visited[i] = 0;
        pre[i] = -1;
    }

    // initialize weight matrix
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            weight[i][j] = 0;

    // read edges
    for (int i = 1; i <= edge; i++)
    {
        cout << "Enter u v w : ";
        cin >> u >> v >> w;
        weight[u][v] = weight[v][u] = w;
    }

    prim();
}
