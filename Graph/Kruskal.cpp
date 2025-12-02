#include <iostream>
using namespace std;

#define MAX 20

struct Edge {
    int u, v, w; 
};

int parent[MAX];

void makeSet(int n) {
    for (int i = 0; i < n; i++)
        parent[i] = i;
}

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]); 
}

void unionSet(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py)
        parent[py] = px; 
}

void sortEdges(Edge edges[], int m) {
    for (int i = 0; i < m - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < m; j++) {
            if (edges[j].w < edges[minIdx].w)
                minIdx = j;
        }
        Edge temp = edges[i];
        edges[i] = edges[minIdx];
        edges[minIdx] = temp;
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    Edge edges[MAX];

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sortEdges(edges, m);

    makeSet(n);

    int mstWeight = 0;
    cout << "Edges in MST:\n";

    for (int i = 0; i < m; i++) {
        int uRep = find(edges[i].u);
        int vRep = find(edges[i].v);

        if (uRep != vRep) {
            cout << edges[i].u << " - " << edges[i].v << " = " << edges[i].w << endl;
            mstWeight += edges[i].w;
            unionSet(uRep, vRep);
        }
    }

    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;
}
