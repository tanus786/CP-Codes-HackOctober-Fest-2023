#include <iostream>
using namespace std;

// Basic Tree Node for Storing the Integers
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
};

// Structure wrapping for the Binary Search Tree
struct BinarySearchTree
{
    TreeNode *root;
};

// Recusive Approach to Search in a Binary Tree
TreeNode *FindValue(TreeNode *current, int target) // In the starting the current will be equal to the root node of the Tree
{
    if (current == NULL) // Checking if the Tree is empty or not
    {
        return NULL;
    }
    else if (current->value == target) // Checking if the current node is of our interest or not
    {
        return current;
    }
    else if (target < current->value && current->left != NULL) // Checking whether to explore the left Subtree or not
    {
        return FindValue(current->left, target);
    }
    else if (target > current->value && current->right != NULL) // Checking whether to explore the right Subtree or not
    {
        return FindValue(current->right, target);
    }
    else // We didn't find any node of our interest
    {
        return NULL;
    }
}

// Iterative Approach to Search in a Binary Tree
TreeNode *FindValueItr(TreeNode *root, int target)
{
    TreeNode *current = root; // Creating a variable to point to the current node in the iteration

    while (current != NULL && current->value != target) // Checking if it the dead end or not
    {
        if (target < current->value) // Checking whether to explore the left SubTree or not
        {
            current = current->left;
        }
        else // Checking the Right SubTree if the Left SubTree is not of our interest
        {
            current = current->right;
        }
    }

    return current; // returning the pointer to the node in which we are interested
}

// Searching for a node in the Binary Tree
TreeNode *FindTreeNode(BinarySearchTree tree, int target)
{
    if (tree.root == NULL) // Checking if the BST is empty or not
    {
        return NULL;
    }

    return FindValue(tree.root, target); // Wrapper Function to find the node inside of the tree
}

// wRAPPER FUNCTION FOR INSERTING THE NODE IN THE BST
void InsertNode(TreeNode *current, int new_value)
{
    if (new_value == current->value) // Checking for the Duplicate value
    {
        return;
    }
    else if (new_value < current->value) // Checking whether to insert the node in left subtree or not
    {
        if (current->left != NULL) // Checking if the space is empty or not to insert the node
        {
            InsertNode(current->left, new_value);
        }
        else
        {
            current->left = new TreeNode;
            current->left->value = new_value;
            current->left->parent = current;
        }
    }
    else // Checking whether to insert the node in right subtree or not
    {
        if (current->right != NULL) // Checking if the space is empty or not to insert the node
        {
            InsertNode(current->right, new_value);
        }
        else
        {
            current->right = new TreeNode;
            current->right->value = new_value;
            current->right->parent = current;
        }
    }
};

// Function to insert a node in the Binary Search Tree
void InsertTreeNode(BinarySearchTree tree, int new_value)
{
    if (tree.root == NULL) // Checking if the Tree is empty or not
    {
        tree.root = new TreeNode;
        tree.root->value = new_value;
    }
    else
    {
        InsertNode(tree.root, new_value); // Inserting the node if the BST is not empty or containing the root node already
    }
}

// Function to delete the taegeted node of the Binary Search Tree
void RemoveTreeNode(BinarySearchTree tree, TreeNode *node)
{
    if (tree.root == NULL || node == NULL) // Checking for if the tree is empty or the targetted node exists or not
    {
        return;
    }

    // CASE-A: Deleting/Removing a leaf node
    if (node->left == NULL && node->right == NULL) // Checking the condition for the node to be a leaf node
    {
        if (node->parent == NULL) // Checking if the parent exists or not, if not we are removing the root node itself
        {
            tree.root = NULL;
        }
        else if (node->parent->left == node) // Checking if the node we are deleteing is the left child or not
        {
            node->parent->left = NULL;
            // delete node;
        }
        else // Checking if the node we are deleteing is the right child or not
        {
            node->parent->right = NULL;
            // delete node;
        }
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        return;
    }

    // CASE-B: Deleting/Removing a node with single child
    if (node->left == NULL || node->right == NULL)
    {
        TreeNode *child = node->left;
        if (node->left == NULL)
        {
            child = node->right;
        }

        child->parent = node->parent;
        if (node->parent == NULL)
        {
            tree.root = child;
        }
        else if (node->parent->left == node)
        {
            node->parent->left = child;
        }
        else
        {
            node->parent->right = child;
        }

        // delete node;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;
        return;
    }

    // CASE-C: Deleting/Removing a node with two Children

    // Finding the successor and splice it out of the tree
    TreeNode *successor = node->right;
    while (successor->left != NULL)
    {
        successor = successor->left;
    }
    RemoveTreeNode(tree, successor); // Removing the successor from its place

    // Insert the successor in the place of deleted node
    if (node->parent == NULL) // Checking if we are removing the root node
    {
        tree.root = successor;
    }
    else if (node->parent->left == node) // Checking whether the node is left child or not
    {
        node->parent->left = successor;
    }
    else // Checking whether the node is left child or not
    {
        node->parent->right = successor;
    }
    successor->parent = node->parent; // Setting the new sucessor relation
    successor->left = node->left;     // Setting the new sucessor relation
    node->left->parent = successor;   // Setting the new sucessor relation

    successor->right = node->right; // Setting the new sucessor relation
    if (node->right != NULL)
    {
        node->right->parent = successor;
    }
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return;
}