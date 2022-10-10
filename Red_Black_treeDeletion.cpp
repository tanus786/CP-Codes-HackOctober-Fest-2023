#include <iostream>
#include <queue>
using namespace std;

enum COLOR { RED, BLACK };

class Node {
public:
int val;
COLOR color;
Node *left, *right, *parent;

Node(int val) : val(val) {
	parent = left = right = NULL;

	color = RED;
}

Node *uncle() {
	if (parent == NULL or parent->parent == NULL)
	return NULL;

	if (parent->isOnLeft())
	
	return parent->parent->right;
	else
	
	return parent->parent->left;
}

bool isOnLeft() { return this == parent->left; }

Node *sibling() {
	
	if (parent == NULL)
	return NULL;

	if (isOnLeft())
	return parent->right;

	return parent->left;
}

void moveDown(Node *nParent) {
	if (parent != NULL) {
	if (isOnLeft()) {
		parent->left = nParent;
	} else {
		parent->right = nParent;
	}
	}
	nParent->parent = parent;
	parent = nParent;
}

bool hasRedChild() {
	return (left != NULL and left->color == RED) or
		(right != NULL and right->color == RED);
}
};

class RBTree {
Node *root;

void leftRotate(Node *x) {
	
	Node *nParent = x->right;

	if (x == root)
	root = nParent;

	x->moveDown(nParent);

	x->right = nParent->left;
	
	if (nParent->left != NULL)
	nParent->left->parent = x;

	nParent->left = x;
}

void rightRotate(Node *x) {
	Node *nParent = x->left;

	if (x == root)
	root = nParent;

	x->moveDown(nParent);

	x->left = nParent->right;
	if (nParent->right != NULL)
	nParent->right->parent = x;

	nParent->right = x;
}

void swapColors(Node *x1, Node *x2) {
	COLOR temp;
	temp = x1->color;
	x1->color = x2->color;
	x2->color = temp;
}

void swapValues(Node *u, Node *v) {
	int temp;
	temp = u->val;
	u->val = v->val;
	v->val = temp;
}

void fixRedRed(Node *x) {
	
	if (x == root) {
	x->color = BLACK;
	return;
	}

	Node *parent = x->parent, *grandparent = parent->parent,
		*uncle = x->uncle();

	if (parent->color != BLACK) {
	if (uncle != NULL && uncle->color == RED) {
		
		parent->color = BLACK;
		uncle->color = BLACK;
		grandparent->color = RED;
		fixRedRed(grandparent);
	} else {
		
		if (parent->isOnLeft()) {
		if (x->isOnLeft()) {
			
			swapColors(parent, grandparent);
		} else {
			leftRotate(parent);
			swapColors(x, grandparent);
		}
		
		rightRotate(grandparent);
		} else {
		if (x->isOnLeft()) {
			
			rightRotate(parent);
			swapColors(x, grandparent);
		} else {
			swapColors(parent, grandparent);
		}

		
		leftRotate(grandparent);
		}
	}
	}
}

Node *successor(Node *x) {
	Node *temp = x;

	while (temp->left != NULL)
	temp = temp->left;

	return temp;
}

Node *BSTreplace(Node *x) {
	
	if (x->left != NULL and x->right != NULL)
	return successor(x->right);


	if (x->left == NULL and x->right == NULL)
	return NULL;

	
	if (x->left != NULL)
	return x->left;
	else
	return x->right;
}


void deleteNode(Node *v) {
	Node *u = BSTreplace(v);

	bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
	Node *parent = v->parent;

	if (u == NULL) {
	
	if (v == root) {
		
		root = NULL;
	} else {
		if (uvBlack) {
		fixDoubleBlack(v);
		} else {
		
		if (v->sibling() != NULL)
			v->sibling()->color = RED;
		}

		if (v->isOnLeft()) {
		parent->left = NULL;
		} else {
		parent->right = NULL;
		}
	}
	delete v;
	return;
	}

	if (v->left == NULL or v->right == NULL) {
	if (v == root) {
		v->val = u->val;
		v->left = v->right = NULL;
		delete u;
	} else {
		if (v->isOnLeft()) {
		parent->left = u;
		} else {
		parent->right = u;
		}
		delete v;
		u->parent = parent;
		if (uvBlack) {
		fixDoubleBlack(u);
		} else {
		u->color = BLACK;
		}
	}
	return;
	}

	swapValues(u, v);
	deleteNode(u);
}

void fixDoubleBlack(Node *x) {
	if (x == root)
	return;

	Node *sibling = x->sibling(), *parent = x->parent;
	if (sibling == NULL) {
	fixDoubleBlack(parent);
	} else {
	if (sibling->color == RED) {
	
		parent->color = RED;
		sibling->color = BLACK;
		if (sibling->isOnLeft()) {
		
		rightRotate(parent);
		} else {
		
		leftRotate(parent);
		}
		fixDoubleBlack(x);
	} else {
		
		if (sibling->hasRedChild()) {
		
		if (sibling->left != NULL and sibling->left->color == RED) {
			if (sibling->isOnLeft()) {
			
			sibling->left->color = sibling->color;
			sibling->color = parent->color;
			rightRotate(parent);
			} else {
			
			sibling->left->color = parent->color;
			rightRotate(sibling);
			leftRotate(parent);
			}
		} else {
			if (sibling->isOnLeft()) {
			
			sibling->right->color = parent->color;
			leftRotate(sibling);
			rightRotate(parent);
			} else {
			
			sibling->right->color = sibling->color;
			sibling->color = parent->color;
			leftRotate(parent);
			}
		}
		parent->color = BLACK;
		} else {
		
		sibling->color = RED;
		if (parent->color == BLACK)
			fixDoubleBlack(parent);
		else
			parent->color = BLACK;
		}
	}
	}
}

void levelOrder(Node *x) {
	if (x == NULL)
	return;

	queue<Node *> q;
	Node *curr;

	q.push(x);

	while (!q.empty()) {
	
	curr = q.front();
	q.pop();

	cout << curr->val << " ";

	if (curr->left != NULL)
		q.push(curr->left);
	if (curr->right != NULL)
		q.push(curr->right);
	}
}

void inorder(Node *x) {
	if (x == NULL)
	return;
	inorder(x->left);
	cout << x->val << " ";
	inorder(x->right);
}

public:
RBTree() { root = NULL; }

Node *getRoot() { return root; }

Node *search(int n) {
	Node *temp = root;
	while (temp != NULL) {
	if (n < temp->val) {
		if (temp->left == NULL)
		break;
		else
		temp = temp->left;
	} else if (n == temp->val) {
		break;
	} else {
		if (temp->right == NULL)
		break;
		else
		temp = temp->right;
	}
	}

	return temp;
}

void insert(int n) {
	Node *newNode = new Node(n);
	if (root == NULL) {
	newNode->color = BLACK;
	root = newNode;
	} else {
	Node *temp = search(n);

	if (temp->val == n) {
		return;
	}

	newNode->parent = temp;

	if (n < temp->val)
		temp->left = newNode;
	else
		temp->right = newNode;

	fixRedRed(newNode);
	}
}

void deleteByVal(int n) {
	if (root == NULL)
	return;

	Node *v = search(n), *u;

	if (v->val != n) {
	cout << "No node found to delete with value:" << n << endl;
	return;
	}

	deleteNode(v);
}

void printInOrder() {
	cout << "Inorder: " << endl;
	if (root == NULL)
	cout << "Tree is empty" << endl;
	else
	inorder(root);
	cout << endl;
}

void printLevelOrder() {
	cout << "Level order: " << endl;
	if (root == NULL)
	cout << "Tree is empty" << endl;
	else
	levelOrder(root);
	cout << endl;
}
};

int main() {
RBTree tree;

tree.insert(7);
tree.insert(3);
tree.insert(18);
tree.insert(10);
tree.insert(22);
tree.insert(8);
tree.insert(11);
tree.insert(26);
tree.insert(2);
tree.insert(6);
tree.insert(13);

tree.printInOrder();
tree.printLevelOrder();

cout<<endl<<"Deleting 18, 11, 3, 10, 22"<<endl;

tree.deleteByVal(18);
tree.deleteByVal(11);
tree.deleteByVal(3);
tree.deleteByVal(10);
tree.deleteByVal(22);

tree.printInOrder();
tree.printLevelOrder();
return 0;
}
