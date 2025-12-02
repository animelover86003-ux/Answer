#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BST
{
public:
    Node *root;
    BST() { root = nullptr; }
    Node *insert(Node *node, int val)
    {
        if (node == nullptr)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }
    Node *findMin(Node *node)
    {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }
    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
            return root;
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    void levelOrder(Node *root)
    {
        if (root == nullptr)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
};
int main()
{
    BST tree;
    int choice, val;
    while (true)
    {
        cout << "\n\n--- BST Operations ---";
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Levelwise Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            tree.root = tree.insert(tree.root, val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            tree.root = tree.deleteNode(tree.root, val);
            break;
        case 3:
            cout << "Levelwise Display: ";
            tree.levelOrder(tree.root);
            cout << endl;
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}