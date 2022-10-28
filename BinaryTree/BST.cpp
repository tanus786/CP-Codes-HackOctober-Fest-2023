#include <iostream>
using namespace std;
// 8 10 1 -1 -1 6 4 -1 -1 7 -1-1 3 -1 14 13 -1 -1 -1
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *createTree()
{
    // base case
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    // Recursive case
    node *root = new node(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = createTree();

    preorder(root);
    cout << "Preorder: " << endl;
    inorder(root);
    cout << "Inorder: " << endl;
    postorder(root);
    cout << "Postorder: " << endl;

    return 0;
}