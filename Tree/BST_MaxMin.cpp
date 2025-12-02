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
    int findMin(Node *node)
    {
        if (node == nullptr)
        {
            cout << "Tree is empty!";
            return -1;
        }
        while (node->left != nullptr)
            node = node->left;
        return node->data;
    }
    int findMax(Node *node)
    {
        if (node == nullptr)
        {
            cout << "Tree is empty!";
            return -1;
        }
        while (node->right != nullptr)
            node = node->right;
        return node->data;
    }
    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
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
        cout << "\n2. Display Inorder";
        cout << "\n3. Find Minimum";
        cout << "\n4. Find Maximum";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            tree.root = tree.insert(tree.root, val);
            break;
        case 2:
            cout << "Inorder Traversal: ";
            tree.inorder(tree.root);
            cout << endl;
            break;
        case 3:
            cout << "Minimum value in BST: " << tree.findMin(tree.root);
            break;
        case 4:
            cout << "Maximum value in BST: " << tree.findMax(tree.root);
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}