#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[50];

// Find parent (with path compression)
int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

// Union of two sets
void union_set(int x, int y) {
    parent[y] = x;
}

int main() {
    int v, e;
    Edge edges[100], result[100];

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "\nEnter edges in format (u v w):\n";
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // Initialize parent
    for (int i = 1; i <= v; i++)
        parent[i] = i;

    // Sort edges by weight (simple bubble sort)
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int totalCost = 0, count = 0;

    // Kruskal's Algorithm
    for (int i = 0; i < e; i++) {
        int pu = find(edges[i].u);
        int pv = find(edges[i].v);

        if (pu != pv) {
            result[count++] = edges[i];
            totalCost += edges[i].w;
            union_set(pu, pv);
        }
    }

    cout << "\nMinimum Spanning Tree:\n";
    for (int i = 0; i < count; i++) {
        cout << result[i].u << " -- " << result[i].v 
             << "  (Weight = " << result[i].w << ")\n";
    }

    cout << "\nTotal Minimum Cost = " << totalCost << "\n";

    return 0;
}
