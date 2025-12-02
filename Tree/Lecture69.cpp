// Tree
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int height = 0;
int nodes = 0;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertIntoBst(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
    {
        root->right = insertIntoBst(root->right, d);
    }
    else
    {
        root->left = insertIntoBst(root->left, d);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

void LevelTravelsal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            height++;
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            nodes++;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *deletenode(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *succ = root->right;
        while (succ->left != NULL)
        {
            succ = succ->left;
        }
        root->data = succ->data;
        root->right = deletenode(root->right, succ->data);

        return root;
    }
}

int max(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int min(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void NRpreorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        cout << temp->data << " ";

        if (temp->right)
            st.push(temp->right);
        if (temp->left)
            st.push(temp->left);
    }
}
void NRinorder(Node *root)
{
    Node *curr = root;
    stack<Node *> st;

    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout << curr->data << " ";

        curr = curr->right;
    }
}

void NRpostorder(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s1, s2;

    s1.push(root);

    while (!s1.empty())
    {
        Node *temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int countLeaf(Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST :";
    takeInput(root);
    LevelTravelsal(root);
    cout << "height :" << height << " Node : " << nodes << endl;

    cout << "Maximum Value in Tree is:" << max(root) << endl;
    cout << "Minimum Value In Tree is " << min(root) << endl;

    cout << "Recursively" << endl;
    cout << "Preorder : " << endl;
    preorder(root);
    cout << endl;
    cout << "inorder : " << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    cout << endl;

    cout << "NON Recursively" << endl;
    cout << "Preorder : " << endl;
    NRpreorder(root);
    cout << endl;
    cout << "inorder : " << endl;
    NRinorder(root);
    cout << endl;
    cout << "Postorder : " << endl;
    NRpostorder(root);
    cout << endl;

    cout << "Number of Leaf Nodes: " << countLeaf(root) << endl;
    cout << endl;

    int value;
    cout << "Enter Value to delete :";
    cin >> value;

    root = deletenode(root, value);
    cout << endl;

    LevelTravelsal(root);

    return 0;
}