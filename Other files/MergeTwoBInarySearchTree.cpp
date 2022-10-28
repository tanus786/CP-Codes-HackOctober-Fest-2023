#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->value = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
vector<int> mergeBST(Node* root1, Node* root2)
{
    vector<int> result;
    stack<Node*> st1, st2;
    while (root1 || root2 || !st1.empty() || !st2.empty()) {
        while (root1) {
            st1.push(root1);
            root1 = root1->left;
        }
        
        while (root2) {
            st2.push(root2);
            root2 = root2->left;
        }
        
        if (st2.empty() || (!st1.empty() && st1.top()->value <= st2.top()->value)) {
            root1 = st1.top();
            st1.pop();
            result.push_back(root1->value);
            root1 = root1->right;
        }

        else {
            root2 = st2.top();
            st2.pop();
            result.push_back(root2->value);
            root2 = root2->right;
        }
    }
    return result;
}


int main()
{
    Node *root1 = NULL, *root2 = NULL;

    root1 = newNode(6);
    root1->left = newNode(3);
    root1->right = newNode(8);

    root2 = newNode(9);
    root2->left = newNode(2);
    root2->right = newNode(12);

    vector<int> ans = mergeBST(root1, root2);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}


