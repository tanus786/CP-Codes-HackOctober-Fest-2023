class Solution {
public:
    void inorder(Node *root, vector<Node*>& nodes) {
        if (!root)
            return;

        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    Node *binaryTreeToBST(Node *root) {
        vector<Node*> nodes;
        inorder(root, nodes);
        vector<int> values;
        
        for (auto node : nodes)
            values.push_back(node->data);

        sort(values.begin(), values.end());

        for (int i = 0; i < nodes.size(); ++i)
            nodes[i]->data = values[i];

        return root;
    }
};
