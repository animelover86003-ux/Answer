#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

Node* head[20];  
int visited[20];

void addEdge(int u, int v) {
    Node* temp = new Node;
    temp->vertex = v;
    temp->next = head[u];
    head[u] = temp;
}

void BFS(int start, int n) {
    queue<int> q;

    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    visited[start] = 1;
    q.push(start);

    cout << "\nBFS Traversal: ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        Node* temp = head[u];
        while (temp != nullptr) {
            int v = temp->vertex;
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, e, u, v;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    // initialize head list
    for (int i = 1; i <= n; i++)
        head[i] = NULL;

    cout << "\nEnter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);   // undirected graph
    }

    int start;
    cout << "\nEnter starting vertex for BFS: ";
    cin >> start;

    BFS(start, n);

    return 0;
}
