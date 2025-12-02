#include <iostream>
#define MAX 20
#define INF 9999

using namespace std;

int minDistance(int dist[], bool visited[], int n) {
    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int n, int cost[MAX][MAX], int start, int end) {
    int dist[MAX];      
    bool visited[MAX];  
    int parent[MAX];    

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;  
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INF && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Shortest distance from " << start << " to " << end << " = " << dist[end] << endl;

    cout << "Path: ";
    int path[MAX], count = 0;
    int temp = end;
    while (temp != -1) {
        path[count++] = temp;
        temp = parent[temp];
    }
    for (int i = count - 1; i >= 0; i--)
        cout << path[i] << (i == 0 ? "\n" : " -> ");
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int cost[MAX][MAX];
    cout << "Enter adjacency matrix (enter 0 if no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (w == 0)
                cost[i][j] = INF; 
            else
                cost[i][j] = w;
        }
    }

    int start, end;
    cout << "Enter starting vertex: ";
    cin >> start;
    cout << "Enter ending vertex: ";
    cin >> end;

    dijkstra(n, cost, start, end);

    return 0;
}
