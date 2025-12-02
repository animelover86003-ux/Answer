#include <iostream>
using namespace std;

int weight[20][20], visited[20], d[20], p[20];
int v, e;

void creategraph()
{
    int i, j, a, b, w;

    cout << "\nEnter number of vertices: ";
    cin >> v;
    cout << "\nEnter number of edges: ";
    cin >> e;

    for (i = 1; i <= v; i++)
    {
        for (j = 1; j <= v; j++)
        {
            weight[i][j] = 0;
        }
        d[i] = 32767;
        visited[i] = 0;
        p[i] = 0;
    }

    for (i = 1; i <= e; i++)
    {
        cout << "Enter edge a, b and weight w: ";
        cin >> a >> b >> w;
        weight[a][b] = weight[b][a] = w;
    }
}

void prim()
{
    int current = 1;
    int totalvisited = 1;
    int mincost, i;
    
    visited[current] = 1;
    d[current] = 0;

    while (totalvisited != v)
    {

        // Update neighbors
        for (i = 1; i <= v; i++)
        {
            if (weight[current][i] != 0 && visited[i] == 0)
            {
                if (d[i] > weight[current][i])
                {
                    d[i] = weight[current][i];
                    p[i] = current;
                }
            }
        }

        // Pick next minimum
        mincost = 32767;
        for (i = 1; i <= v; i++)
        {
            if (!visited[i] && d[i] < mincost)
            {
                mincost = d[i];
                current = i;
            }
        }

        visited[current] = 1;
        totalvisited++;
    }

    // Print MST
    mincost = 0;
    for (i = 1; i <= v; i++)
        mincost += d[i];

    cout << "\nMinimum cost = " << mincost;

    cout << "\nMinimum spanning tree:";
    for (i = 1; i <= v; i++)
        cout << "\nVertex " << i << " is connected to " << p[i];
}

int main()
{
    creategraph();
    prim();
    return 0;
}
