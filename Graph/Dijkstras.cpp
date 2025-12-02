#include <iostream>
using namespace std;

int main() {
    int v, e;
    int graph[20][20];
    int dist[20], visited[20];
    int src;

    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize adjacency matrix
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            graph[i][j] = 0;

    // Read edges
    cout << "\nEnter edges in format (u v w):\n";
    for (int i = 1; i <= e; i++) {
        int u, v1, w;
        cin >> u >> v1 >> w;
        graph[u][v1] = w;
        graph[v1][u] = w;  // remove if directed
    }

    cout << "\nEnter source vertex: ";
    cin >> src;

    // Initialize distances and visited
    for (int i = 1; i <= v; i++) {
        dist[i] = 9999;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Dijkstra algorithm
    for (int count = 1; count <= v - 1; count++) {

        int u = -1;
        int minDist = 9999;

        // Find unvisited vertex with minimum distance
        for (int i = 1; i <= v; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Relaxation
        for (int j = 1; j <= v; j++) {
            if (graph[u][j] != 0 && !visited[j]) {
                if (dist[u] + graph[u][j] < dist[j]) {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // Print all distances from source
    cout << "\nShortest distances from source " << src << ":\n";
    for (int i = 1; i <= v; i++) {
        cout << "To " << i << " = " << dist[i] << "\n";
    }

    return 0;
}
