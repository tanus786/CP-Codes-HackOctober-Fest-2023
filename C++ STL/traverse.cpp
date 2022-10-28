// C++ program to find the number of ways to traverse a
// n-ary tree starting from the root node
#include <bits/stdc++.h>
using namespace std;

// Structure of a node of an n-ary tree
struct Node
{
char key;
vector<Node *> child;
};

// Utility function to create a new tree node
Node *newNode(int key)
{
Node *temp = new Node;
temp->key = key;
return temp;
}

// Utility Function to find factorial of given number
int factorial(int n)
{
if (n == 0)
	return 1;
return n*factorial(n-1);
}

// Function to calculate the number of ways of traversing
// the n-ary starting from root.
// This function is just a modified breadth-first search.
// We can use a depth-first search too.
int calculateWays(Node * root)
{
int ways = 1; // Initialize result

// If the tree is empty there is no way of traversing
// the tree.
if (root == NULL)
	return 0;

// Create a queue and enqueue root to it.
queue<Node *>q;
q.push(root);

// Level order traversal.
while (!q.empty())
{
		// Dequeue an item from queue and print it
		Node * p = q.front();
		q.pop();

		// The number of ways is the product of
		// factorials of number of children of each node.
		ways = ways*(factorial(p->child.size()));

		// Enqueue all childrent of the dequeued item
		for (int i=0; i<p->child.size(); i++)
			q.push(p->child[i]);
	}

return(ways);
}

// Driver program
int main()
{
/* Let us create below tree
*		 A
*		 / / \ \
*	 B F D E
*	 / \	 | /|\
*	 K J G C H I
*	 /\		 \
* N M		 L
*/

Node *root = newNode('A');
(root->child).push_back(newNode('B'));
(root->child).push_back(newNode('F'));
(root->child).push_back(newNode('D'));
(root->child).push_back(newNode('E'));
(root->child[0]->child).push_back(newNode('K'));
(root->child[0]->child).push_back(newNode('J'));
(root->child[2]->child).push_back(newNode('G'));
(root->child[3]->child).push_back(newNode('C'));
(root->child[3]->child).push_back(newNode('H'));
(root->child[3]->child).push_back(newNode('I'));
(root->child[0]->child[0]->child).push_back(newNode('N'));
(root->child[0]->child[0]->child).push_back(newNode('M'));
(root->child[3]->child[2]->child).push_back(newNode('L'));

cout << calculateWays(root); ;

return 0;
}
