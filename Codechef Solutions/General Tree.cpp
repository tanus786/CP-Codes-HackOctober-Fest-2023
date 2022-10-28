// CPP program to do level order traversal
// of a generic tree
#include <bits/stdc++.h>
using namespace std;

// Represents a node of an n-ary tree
struct Node
{
	int key;
	vector<Node *>child;
};

// Utility function to create a new tree node
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	return temp;
}

// Prints the n-ary tree level wise
void LevelOrderTraversal(Node * root)
{
	if (root==NULL)
		return;

	// Standard level order traversal code
	// using queue
	queue<Node *> q; // Create a queue
	q.push(root); // Enqueue root
	while (!q.empty())
	{
		int n = q.size();

		// If this node has children
		while (n > 0)
		{
			// Dequeue an item from queue and print it
			Node * p = q.front();
			q.pop();
			cout << p->key << " ";

			// Enqueue all children of the dequeued item
			for (int i=0; i<p->child.size(); i++)
				q.push(p->child[i]);
			n--;
		}

		cout << endl; // Print new line between two levels
	}
}

// Driver program
int main()
{
	/* Let us create below tree
	*			 10
	*	 / / \ \
	*	 2 34 56 100
	*	 / \		 | / | \
	*	 77 88	 1 7 8 9
	*/
	Node *root = newNode(10);
	(root->child).push_back(newNode(2));
	(root->child).push_back(newNode(34));
	(root->child).push_back(newNode(56));
	(root->child).push_back(newNode(100));
	(root->child[0]->child).push_back(newNode(77));
	(root->child[0]->child).push_back(newNode(88));
	(root->child[2]->child).push_back(newNode(1));
	(root->child[3]->child).push_back(newNode(7));
	(root->child[3]->child).push_back(newNode(8));
	(root->child[3]->child).push_back(newNode(9));

	cout << "Level order traversal Before Mirroring\n";
	LevelOrderTraversal(root);

	return 0;
}
