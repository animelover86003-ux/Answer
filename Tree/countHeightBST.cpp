#include <iostream>
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
    int countNodes(Node *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        int l = height(node->left);
        int r = height(node->right);
        return 1 + max(l, r);
    }
    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void mirror(Node *node)
    {
        if (node == nullptr)
            return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
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
        cout << "\n2. Count Total Nodes";
        cout << "\n3. Compute Height";
        cout << "\n4. Display Inorder";
        cout << "\n5. Mirror Image";
        cout << "\n6. Exit";
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
            cout << "Total number of nodes: " << tree.countNodes(tree.root);
            break;
        case 3:
            cout << "Height of BST: " << tree.height(tree.root);
            break;
        case 4:
            cout << "Inorder Traversal: ";
            tree.inorder(tree.root);
            cout << endl;
            break;
        case 5:
            cout << "BST Mirrored Successfully.\n";
            tree.mirror(tree.root);
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}
