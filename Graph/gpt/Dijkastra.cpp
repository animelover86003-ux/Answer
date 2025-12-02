#include<iostream>
using namespace std;

struct node {
    int v, w;
    node *next;
} *head[20];

int dist[20], visited[20];
int n;

void addEdge(int u, int v, int w)
{
    node *p = new node;
    p->v = v; p->w = w;
    p->next = head[u];
    head[u] = p;
}

void dijkstra(int start)
{
    for(int i=1;i<=n;i++)
    {
        dist[i] = 32767;
        visited[i] = 0;
    }

    dist[start] = 0;

    for(int c=1;c<=n;c++)
    {
        int u = 0, min = 32767;

        for(int i=1;i<=n;i++)
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        node *p = head[u];
        while(p != NULL)
        {
            if(!visited[p->v] && dist[p->v] > dist[u] + p->w)
                dist[p->v] = dist[u] + p->w;

            p = p->next;
        }
    }

    cout<<"\nShortest Distance from "<<start<<" :\n";
    for(int i=1;i<=n;i++)
        cout<<start<<" -> "<<i<<" = "<<dist[i]<<"\n";
}

void main()
{
    int e,u,v,w,start;

    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>e;

    for(int i=1;i<=n;i++)
        head[i] = NULL;

    for(int i=1;i<=e;i++)
    {
        cout<<"Enter edge (u v w): ";
        cin>>u>>v>>w;
        addEdge(u,v,w);
        addEdge(v,u,w);
    }

    cout<<"Enter source vertex: ";
    cin>>start;

    dijkstra(start);
}
