#include <iostream>

// Define a basic structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    
    // Insert nodes into the binary tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Perform an inorder traversal to print the elements in sorted order
    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
