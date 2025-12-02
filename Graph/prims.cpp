#include <iostream>
using namespace std;

#define MAX 20
#define INF 9999

int n;                  
int cost[MAX][MAX];      
bool visited[MAX];       

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (use " << INF << " for no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = false;

    visited[0] = true;  
    int edges = 0;
    int minCost = 0;

    cout << "Edges in MST:\n";

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            cout << u << " - " << v << " = " << cost[u][v] << endl;
            minCost += cost[u][v];
            visited[v] = true;
            edges++;
        }
    }

    cout << "Total cost of MST: " << minCost << endl;

    return 0;
}
