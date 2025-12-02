#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Stack {
public:
    Node* arr[200];
    int top;

    Stack() { top = -1; }

    void push(Node* x) {
        arr[++top] = x;
    }

    Node* pop() {
        return arr[top--];
    }

    bool empty() {
        return top == -1;
    }
};


class Queue {
public:
    Node* arr[200];
    int front, rear, size;

    Queue() {
        front = rear = -1;
        size = 200;
    }

    bool empty() {
        return front == -1;
    }

    void push(Node* x) {
        if ((rear + 1) % size == front) return; // full
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = x;
    }

    Node* pop() {
        if (empty()) return nullptr;
        Node* temp = arr[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;

        return temp;
    }
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() { root = nullptr; }

    Node* create() {
        int val;
        cout << "Enter data (-1 for no node): ";
        cin >> val;

        if (val == -1) return nullptr;

        Node* newNode = new Node(val);
        cout << "Enter left child of " << val << ": ";
        newNode->left = create();
        cout << "Enter right child of " << val << ": ";
        newNode->right = create();

        return newNode;
    }

    void inorderNonRecursive(Node* root) {
        Stack st;
        Node* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }

    void preorderNonRecursive(Node* root) {
        if (root == nullptr) return;

        Stack st;
        st.push(root);

        while (!st.empty()) {
            Node* curr = st.pop();
            cout << curr->data << " ";

            if (curr->right) st.push(curr->right);
            if (curr->left)  st.push(curr->left);
        }
    }

    int countLeafNodes(Node* root) {
        if (!root) return 0;

        Stack st;
        st.push(root);
        int count = 0;

        while (!st.empty()) {
            Node* curr = st.pop();

            if (!curr->left && !curr->right)
                count++;

            if (curr->right) st.push(curr->right);
            if (curr->left)  st.push(curr->left);
        }
        return count;
    }


    void mirror(Node* root) {
        if (root == nullptr) return;

        Queue q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.pop();

            Node* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
};


int main() {
    BinaryTree tree;
    int choice;

    while (true) {
        cout << "\n\n--- Binary Tree Non-Recursive Operations ---";
        cout << "\n1. Create Tree";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Count Leaf Nodes";
        cout << "\n5. Mirror Image";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.root = tree.create();
                break;

            case 2:
                cout << "Inorder Traversal: ";
                tree.inorderNonRecursive(tree.root);
                break;

            case 3:
                cout << "Preorder Traversal: ";
                tree.preorderNonRecursive(tree.root);
                break;

            case 4:
                cout << "Number of Leaf Nodes: " 
                     << tree.countLeafNodes(tree.root);
                break;

            case 5:
                tree.mirror(tree.root);
                cout << "Mirror Image created successfully!";
                break;

            case 6:
                return 0;
        }
    }
}
