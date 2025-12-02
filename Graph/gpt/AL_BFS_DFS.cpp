#include<iostream>
using namespace std;
struct node {
    int v;
    node *next;
} *head[20];

int visited[20], q[20], front=-1, rear=-1;
int n;

void addEdge(int u, int v)
{
    node *p = new node;
    p->v = v;
    p->next = head[u];
    head[u] = p;
}

void dfs(int start)
{
    visited[start] = 1;
    cout<<start<<" ";

    node *p = head[start];
    while(p != NULL)
    {
        if(!visited[p->v])
            dfs(p->v);

        p = p->next;
    }
}

void bfs(int start)
{
    for(int i=1;i<=n;i++)
        visited[i] = 0;

    front = rear = -1;
    q[++rear] = start;
    visited[start] = 1;

    cout<<"\nBFS: ";

    while(front != rear)
    {
        int u = q[++front];
        cout<<u<<" ";

        node *p = head[u];
        while(p != NULL)
        {
            if(!visited[p->v])
            {
                visited[p->v] = 1;
                q[++rear] = p->v;
            }
            p = p->next;
        }
    }
}

void main()
{
    int e,u,v;

    cout<<"Enter vertices: ";
    cin>>n;
    cout<<"Enter edges: ";
    cin>>e;

    for(int i=1;i<=n;i++)
        head[i] = NULL;

    for(int i=1;i<=e;i++)
    {
        cout<<"Enter edge (u v): ";
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }

    cout<<"DFS starting vertex: ";
    cin>>u;

    for(int i=1;i<=n;i++) visited[i]=0;
    cout<<"DFS: ";
    dfs(u);

    cout<<"\nBFS starting vertex: ";
    cin>>v;
    bfs(v);

}
