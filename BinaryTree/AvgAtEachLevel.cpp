// C++ program to find averages of all levels
// in a binary tree.
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to
   left child and a pointer to right child */
struct Node {
    int val;
    struct Node* left, *right;
};
 
/* Function to print the average value of the
   nodes on each level */
void averageOfLevels(Node* root)
{
    vector<float> res;
 
    // Traversing level by level
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
 
        // Compute sum of nodes and
        // count of nodes in current
        // level.
        int sum = 0, count = 0;
        queue<Node*> temp;
        while (!q.empty()) {
            Node* n = q.front();
            q.pop();
            sum += n->val;
            count++;
            if (n->left != NULL)
                temp.push(n->left);
            if (n->right != NULL)
                temp.push(n->right);
        }
        q = temp;
        cout << (sum * 1.0 / count) << " ";
    }
}
 
/* Helper function that allocates a
   new node with the given data and
   NULL left and right pointers. */
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver code
int main()
{
    /* Let us construct a Binary Tree
        4
       / \
      2   9
     / \   \
    3   5   7 */
 
    Node* root = NULL;
    root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(9);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    root->right->right = newNode(7);
    averageOfLevels(root);
    return 0;
}
