#include<iostream>
using namespace std;
struct edge {
    int u, v, w;
} E[50];

int parent[20];
int n, e;

int find(int x)
{
    while(parent[x] != x) x = parent[x];
    return x;
}

void uni(int a, int b)
{
    parent[a] = b;
}

void main()
{
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>e;

    for(int i=1;i<=n;i++)
        parent[i] = i;

    for(int i=1;i<=e;i++)
    {
        cout<<"Enter edge (u v w): ";
        cin>>E[i].u>>E[i].v>>E[i].w;
    }

    // sort edges by weight (simple bubble sort)
    for(int i=1;i<=e;i++)
        for(int j=1;j<=e-i;j++)
            if(E[j].w > E[j+1].w)
            {
                edge temp = E[j];
                E[j] = E[j+1];
                E[j+1] = temp;
            }

    int count = 0, cost = 0;
    cout<<"\nEdges in MST:\n";

    for(int i=1;i<=e;i++)
    {
        int a = find(E[i].u);
        int b = find(E[i].v);

        if(a != b)
        {
            cout<<E[i].u<<" -> "<<E[i].v<<"  ( "<<E[i].w<<" )\n";
            cost += E[i].w;
            uni(a,b);
            count++;
            if(count == n-1) break;
        }
    }

    cout<<"\nMinimum Cost = "<<cost;

}
