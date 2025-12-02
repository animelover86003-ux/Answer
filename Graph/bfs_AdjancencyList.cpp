#include <iostream>
using namespace std;

#define MAX 20


struct Node {
    int data;
    Node* next;
};

Node* adjList[MAX];

bool visited[MAX];

int n;


class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void push(int x) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int pop() {
        if (isEmpty()) return -1;
        int t = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return t;
    }
};


void BFS(int start) {
    Queue q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (!q.isEmpty()) {
        int v = q.pop();
        cout << v << " ";

        Node* temp = adjList[v];

        while (temp != nullptr) {
            int neigh = temp->data;

            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }

            temp = temp->next;
        }
    }

    cout << endl;
}


int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        adjList[i] = nullptr;

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v) meaning u is connected to v:\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        Node* newNode = new Node;
        newNode->data = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;

        Node* newNode2 = new Node;
        newNode2->data = u;
        newNode2->next = adjList[v];
        adjList[v] = newNode2;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    for (int i = 0; i < n; i++)
        visited[i] = false;

    BFS(start);

    return 0;
}
