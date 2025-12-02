#include <iostream>
#include <conio.h>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int v) { data = v; left = right = NULL; }
};

Node* createTree() {
    int x;
    cout << "Enter data (-1 for NULL): ";
    cin >> x;

    if (x == -1) return NULL;

    Node* n = new Node(x);

    cout << "Left child of " << x << endl;
    n->left = createTree();

    cout << "Right child of " << x << endl;
    n->right = createTree();

    return n;
}

void inorder(Node* r) {
    if (r) {
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
}

void preorder(Node* r) {
    if (r) {
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
}

int leafCount(Node* r) {
    if (!r) return 0;
    if (!r->left && !r->right) return 1;
    return leafCount(r->left) + leafCount(r->right);
}

void mirror(Node* r) {
    if (!r) return;
    Node* temp = r->left;
    r->left = r->right;
    r->right = temp;
    mirror(r->left);
    mirror(r->right);
}

void main() {

    Node* root = createTree();

    cout << "\nInorder (R): ";
    inorder(root);

    cout << "\nPreorder (R): ";
    preorder(root);

    cout << "\nLeaf Count = " << leafCount(root);

    mirror(root);

    cout << "\nAfter Mirror Inorder: ";
    inorder(root);

    getch();
}
